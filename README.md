# clogger

My personal and minimal implementation of a logging module, written in C.

## Setup

This module, once completed, will be able to be set up for use via a drag-n-drop approach, a static
library, and a shared library.

### Drag-n-Drop
To set up using the drag-n-drop approach, simply add `clogger.h` and `clogger.c` wherever your
header and source files reside, respectively. There are currently no external dependencies
besides `libc`, so the translation unit will be able to compile standalone.

### Static Library
To set up using the static library approach, use `make static` to generate a static library in
`bin/static` or `make install_static` to generate the static library and install it in
`/usr/local/lib` as `libclogger-static.a`.

### Shared Library
To set up using the shared library approach, use `make shared` to generate a shared library in
`bin/shared` or `make install_shared` to generate the shared library and install it in
`/usr/local/lib` as `libclogger.so`.

## Usage

This library currently provides four levels at which messages can be logged:

- `LOGLEVEL_DEBUG`
- `LOGLEVEL_VERBOSE`
- `LOGLEVEL_INFO`
- `LOGLEVEL_ERROR`

where (in the order presnted) `LOGLEVEL_ERROR` represents the "lowest" level and `LOGLEVEL_DEBUG`
represents the "highest".

This library defaults to logging to `stdout` at `LOGLEVEL_INFO`, but can be initialized using
`clogger_init()` to log to a specific file (`FILE *`) and a specific level (`LogLevel`). This
logger will only output messages that are lower than the specified `LogLevel`.

To create logged output, the `clogger_log()` function is provided, which takes as input the
logging level associated with the message, and `printf`-style input of the message itself. Four
convenience macro definitions are also provided (one corresponding to each `LogLevel`) so as to
save some typing:

- `clogger_debug()`
- `clogger_verbose()`
- `clogger_info()`
- `clogger_error()`

all of which also take `printf`-style input for the message to be logged.
