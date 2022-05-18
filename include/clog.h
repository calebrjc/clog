#ifndef CALEBRJC_CLOG_CLOG_H_
#define CALEBRJC_CLOG_CLOG_H_

#include <stdio.h>

// Represents the different levels that a message may be logged at.
typedef enum {
    CLOG_LOGLEVEL_NONE    = 0,
    CLOG_LOGLEVEL_DEBUG   = 1,
    CLOG_LOGLEVEL_VERBOSE = 2,
    CLOG_LOGLEVEL_INFO    = 3,
    CLOG_LOGLEVEL_ERROR   = 4
} LogLevel;

// Initializes clog to log to `file` at the log level specified by `level`.
//
// No logs will be output from clog until this function is called at least once. Calling this
// function with `file == NULL` is equivalent to calling this function with `file == stdout`.
void clog_init(FILE *fp, LogLevel level);

// Logs the message with at the level specified using printf-style formatting.
void clog_log(LogLevel level, const char *format, ...);

// Equivalent to `clog_log(CLOG_LOGLEVEL_DEBUG, format, ...)`
#define clog_debug(...) clog_log(CLOG_LOGLEVEL_DEBUG, __VA_ARGS__)

// Equivalent to `clog_log(CLOG_LOGLEVEL_VERBOSE, format, ...)`
#define clog_verbose(...) clog_log(CLOG_LOGLEVEL_VERBOSE, __VA_ARGS__)

// Equivalent to `clog_log(CLOG_LOGLEVEL_INFO, format, ...)`
#define clog_info(...) clog_log(CLOG_LOGLEVEL_INFO, __VA_ARGS__)

// Equivalent to `clog_log(CLOG_LOGLEVEL_ERROR, format, ...)`
#define clog_error(...) clog_log(CLOG_LOGLEVEL_ERROR, __VA_ARGS__)

#endif  // CALEBRJC_CLOG_CLOG_H_
