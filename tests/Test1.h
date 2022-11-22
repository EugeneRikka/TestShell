#pragma once

#include "testShell/Test.h"

DEFINE_TEST(Test1)

void Test1::init() {
}

void Test1::run() {
    std::cout << name << std::endl;
}