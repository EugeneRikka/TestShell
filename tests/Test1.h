#pragma once

#include "testShell/Test.h"

class Test1 : public Test {
public:
    Test1() : Test("Test1") {
    }

    void run() override {
        std::cout << name << std::endl;
    }
};

extern Test1 test1;