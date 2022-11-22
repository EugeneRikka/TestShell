#pragma once

#include "testShell/Test.h"

DEFINE_TEST(Test2)

void Test2::init() {
}

void Test2::run() {
    std::cout << name << "hahaha" << std::endl;
}