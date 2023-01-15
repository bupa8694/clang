//
// Created by zebra on 1/15/23.
//

#include "tata.h"
#include "logger.h"

extern logger&& hypLogger;

void tata::foo() {
    hypLogger.writer<QTGUI>("QTGUI Logging");
}
