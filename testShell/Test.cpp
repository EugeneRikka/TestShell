#include "Test.h"

Test::Test(const char* name) : name(name) {
    tests.push_back(this);
}

std::vector<Test*> Test::tests;
