//
// Created by zebra on 1/12/23.
//
#include "logger.h"

logger&& get_logger()
{
    static logger logger;
    return std::move(logger);
}

logger::logger(){

}

logger::~logger() {

}