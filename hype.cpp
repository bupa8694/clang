//
// Created by zebra on 1/11/23.
//
#include "logger.h"
#include "hype.h"
extern logger&& hypLogger;

void  hyper_connection() {
    hypLogger.writer<Console>("Console  hype Logging");
}
