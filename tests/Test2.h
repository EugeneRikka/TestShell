#pragma once

#include "testShell/Test.h"

DEFINE_TEST(Test2)

void Test2::init() {
    testData.setCasesType(CasesType::Pairs);
    testData.registerField<double>("numenator", {3.0, -3.0, 0.0});
    testData.registerField<double>("denumenator", {-2.0, 0.0, 0.0});
}

std::string Test2::info() {
    auto numenator = testData.getField<double>("numenator");
    auto denumenator = testData.getField<double>("denumenator");
    return "numenator = " + std::to_string(numenator) + ", denumenator = " + std::to_string(denumenator);
}

void Test2::run() {
    auto numenator = testData.getField<double>("numenator");
    auto denumenator = testData.getField<double>("denumenator");

    double res = numenator / denumenator;
}