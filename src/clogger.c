// File: clogger.c
// Author(s): Caleb Johnson-Cantrell

#include "clogger.h"

#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

// The current file being logged to
static FILE *log_file = NULL;

// The current log level
static LogLevel current_level = LOGLEVEL_INFO;

// Logging headers
char *LOG_HEADERS[] = {
    "DEBUG",    // LogLevel.DEBUG
    "VERBOSE",  // LogLevel.VERBOSE
    "",         // LogLevel.INFO
    "ERROR",    // LogLevel.ERROR
};

void clogger_init(FILE *fp, LogLevel level) {
    log_file = fp;
    current_level = level;
}

void clogger_log(LogLevel level, const char *format, ...) {
    // Abort if the current level doesn't allow for this message to be printed
    if (level < current_level) return;

    // Determine the file stream that this message should be printed to
    FILE *fp = (log_file) ? log_file : stdout;

    // If the message requires a header, add it
    if (strlen(LOG_HEADERS[level]) > 0) {
        fprintf(fp, "[%s] ", LOG_HEADERS[level]);   
    }

    // Print this message to the specified file stream
    va_list args;
    va_start(args, format);
    vfprintf(fp, format, args);
    va_end(args);
}