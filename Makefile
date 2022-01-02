# File: Makefile
# Author(s): Caleb Johnson-Cantrell

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

# Recipes
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

dropintest: $(TEST)/library_test.c $(OBJ)/clogger.o | $(BIN)/tests
	$(CC) $(CFLAGS) -o $(BIN)/tests/$@ $^

sharedtest: $(TEST)/library_test.c libclogger.so | $(BIN)/tests
	$(CC) $(CFLAGS) -o $(BIN)/tests/$@ $< -L$(BIN)/shared -lclogger

statictest: $(TEST)/library_test.c libclogger-static.a | $(BIN)/tests
	$(CC) $(CFLAGS) -o $(BIN)/tests/$@ $< -L$(BIN)/static -lclogger-static

libclogger.so: CFLAGS += -fPIC
libclogger.so: $(SRC)/clogger.c $(INC)/clogger.h | $(BIN)/shared
	$(CC) $(CFLAGS) -shared -o $(BIN)/shared/$@ $< -lc

libclogger-static.a: $(OBJ)/clogger.o | $(BIN)/static
	$(AR) $(ARFLAGS) $(BIN)/static/$@ $(OBJ)/clogger.o

$(OBJ)/%.o: $(SRC)/%.c $(INC)/%.h | $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BIN) $(BIN)/tests $(BIN)/shared $(BIN)/static $(OBJ):
	$(MKDIR) $(MKDIRFLAGS) $@

clean:
	$(RM) $(RMFLAGS) obj bin
