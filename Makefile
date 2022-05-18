# Tool and option aliases
CC         = gcc
CFLAGS     = -Wall --pedantic-errors -g -I$(INC)
RM         = rm
RMFLAGS    = -rf
MKDIR      = mkdir
MKDIRFLAGS = -p
AR         = ar
ARFLAGS    = rcs

# Directory variables
SRC  = src
TEST = test
OBJ  = obj
BIN  = bin
INC  = include

# Rules
all: dropintest sharedtest statictest

install: install_shared install_static

install_shared: shared
	@cp $(BIN)/shared/libclogger.so /usr/local/lib
	@ldconfig

install_static: static
	@cp $(BIN)/static/libclogger-static.a /usr/local/lib
	@ldconfig

shared: libclogger.so

static: libclogger-static.a

dropintest: $(TEST)/library_test.c $(OBJ)/clog.o | $(BIN)/tests
	$(CC) $(CFLAGS) -o $(BIN)/tests/$@ $^

sharedtest: $(TEST)/library_test.c libclog.so | $(BIN)/tests
	$(CC) $(CFLAGS) -o $(BIN)/tests/$@ $< -L$(BIN)/shared -lclog

statictest: $(TEST)/library_test.c libclog-static.a | $(BIN)/tests
	$(CC) $(CFLAGS) -o $(BIN)/tests/$@ $< -L$(BIN)/static -lclog-static

libclog.so: CFLAGS += -fPIC
libclog.so: $(SRC)/clog.c $(INC)/clog.h | $(BIN)/shared
	$(CC) $(CFLAGS) -shared -o $(BIN)/shared/$@ $< -lc

libclog-static.a: $(OBJ)/clog.o | $(BIN)/static
	$(AR) $(ARFLAGS) $(BIN)/static/$@ $(OBJ)/clog.o

$(OBJ)/%.o: $(SRC)/%.c $(INC)/%.h | $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BIN) $(BIN)/tests $(BIN)/shared $(BIN)/static $(OBJ):
	$(MKDIR) $(MKDIRFLAGS) $@

clean:
	$(RM) $(RMFLAGS) obj bin
