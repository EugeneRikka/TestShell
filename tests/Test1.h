#pragma once

#include "testShell/Test.h"

DEFINE_TEST(Test1)

void Test1::init() {
    testData.setCasesType(CasesType::Combinations);
    testData.registerField<int>("a", {1, 2, 3});
    testData.registerField<std::string>("b", {"5", "6", "8", "9"});
}

std::string Test1::info() {
    auto a = testData.getField<int>("a");
    auto b = testData.getField<std::string>("b");
    return "a = " + std::to_string(a) + ", b = " + b;
}

void Test1::run() {
    auto a = testData.getField<int>("a");
    auto b = testData.getField<std::string>("b");

    b += std::to_string(a);
}