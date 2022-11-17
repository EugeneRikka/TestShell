#pragma once

#include <iostream>
#include <vector>

class Test {
protected:
    std::string name;

public:
    static std::vector<Test*> tests;

    Test(const char* name);

    virtual void run() = 0;
};