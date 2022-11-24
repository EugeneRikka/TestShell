#pragma once

#include "testShell/Test.h"

DEFINE_TEST(Test3)

void Test3::init() {
    testData.setCasesType(CasesType::NoFields);
}

std::string Test3::info() {
    return "2 * 2 == 5?";
}

void Test3::run() {
    if (2 * 2 != 5) {
        throw std::runtime_error("cringe");
    }
}