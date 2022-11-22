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

    Test(const Test &other) = delete;
    void operator=(const Test &other) = delete;
    Test(const Test &&other) = delete;
    void operator=(const Test &&other) = delete;
    
    virtual void init() = 0;
    virtual void run() = 0;
};

std::vector<Test*> Test::tests;

#define DEFINE_TEST(TestName)            \
class TestName : public Test {           \
private:                                 \
    static TestName obj##TestName;       \
                                         \
    TestName() : Test(#TestName) {       \
    }                                    \
                                         \
public:                                  \
    void init() override;                \
    void run() override;                 \
};                                       \
                                         \
TestName TestName::obj##TestName;