# clogger

My personal, minimal implementation of a logging module, written in C.

## Setup

This module, once completed, will be able to be set up for use in three ways: a simple drag-n-drop
approach, a static library, and a shared library.

## Usage

This library currently provides four levels that you can use to log your messages:

- `LOGLEVEL_DEBUG`
- `LOGLEVEL_VERBOSE`
- `LOGLEVEL_INFO`
- `LOGLEVEL_ERROR`

where (in the order presnted) `LOGLEVEL_ERROR` represents the "lowest" level and `LOGLEVEL_DEBUG` represents the "highest".

This library defaults to logging to `stdout` at `LOGLEVEL_INFO`, but can be initialized using `clogger_init()` to log to a specific file and a specific `LogLevel`. This logger will only output messages that are lower than the specified `LogLevel`.

To create logged output, the `clogger_log()` function is provided, which takes as input the `LogLevel` associated with the message being logged, and `printf`-style input of the message itself. Four convenience functions are also provided (one corresponding to each `LogLevel`) so as to save some typing:

- `clogger_debug()`
- `clogger_verbose()`
- `clogger_info()`
- `clogger_error()`

all of which also take `printf`-style input for the message to be logged.