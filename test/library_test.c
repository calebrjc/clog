#include "clogger.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
    clogger_init(NULL, LOGLEVEL_DEBUG);
    clogger_debug("I'm trying\n");
    clogger_info("Trying again\n");
    clogger_verbose("One more time\n");
    clogger_error("Error!\n");
}