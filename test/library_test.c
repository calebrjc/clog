#include "clog.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
    clog_init(NULL, CLOG_LOGLEVEL_INFO);
    clog_debug("I'm trying\n");
    clog_verbose("One more time\n");
    clog_info("Trying again\n");
    clog_error("Error!\n");
}
