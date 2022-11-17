#pragma once

#include "testShell/Test.h"

class Test2 : public Test {
public:
    Test2() : Test("Test2") {
    }

    void run() override {
        std::cout << name << "hahaha" << std::endl;
    }
};

extern Test2 test2;