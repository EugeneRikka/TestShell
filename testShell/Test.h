#pragma once

#include <iostream>
#include <vector>

class Test {
protected:
    std::string name;

    Test(const char* name) : name(name) {
        tests.push_back(this);
    }

public:
    static std::vector<Test*> tests;

    virtual void init() = 0;
    virtual void run() = 0;
};

std::vector<Test*> Test::tests;

#define DEFINE_TEST(TestName)            \
class TestName : public Test {           \
public:                                  \
    TestName() : Test(#TestName) {       \
    }                                    \
                                         \
    void init() override;                \
    void run() override;                 \
};                                       \
                                         \
static TestName obj##TestName;
