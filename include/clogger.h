// File: include/clogger.h
// Author(s): Caleb Johnson-Cantrell

#ifndef CALEBRJC_CLOGGER_CLOGGER_H_
#define CALEBRJC_CLOGGER_CLOGGER_H_

#include <stdio.h>

// Defines the different levels that messages can be logged at.
typedef enum log_level_t {
  LOGLEVEL_DEBUG = 0,
  LOGLEVEL_VERBOSE = 1,
  LOGLEVEL_INFO = 2,
  LOGLEVEL_ERROR = 3
} LogLevel;

// Sets clogger to output to the specified `FILE *fp` with the log level
// `level`.
//
// Calling this with `fp == NULL` is equivalent to setting the output file to
// stdout.
void clogger_init(FILE *fp, LogLevel level);

// A printf-style function that logs the message with a LogLevel of `level` to
// the file specified in `clogger_init()` or `stdout` if the file was never
// specified.
void clogger_log(LogLevel level, const char *format, ...);

// Equivalent to `logger_log(LOGLEVEL_DEBUG, format, ...)`
#define clogger_debug(...) \
  clogger_log(LOGLEVEL_DEBUG, __VA_ARGS__)

// Equivalent to `logger_log(LOGLEVEL_VERBOSE, format, ...)`
#define clogger_verbose(...) \
  clogger_log(LOGLEVEL_VERBOSE, __VA_ARGS__)

// Equivalent to `logger_log(LOGLEVEL_INFO, format, ...)`
#define clogger_info(...) \
  clogger_log(LOGLEVEL_INFO, __VA_ARGS__)

// Equivalent to `logger_log(LOGLEVEL_ERROR, format, ...)`
#define clogger_error(...) \
  clogger_log(LOGLEVEL_ERROR, __VA_ARGS__)

#endif  // CALEBRJC_CLOGGER_CLOGGER_H_
