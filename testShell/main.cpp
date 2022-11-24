#include "Test.h"

bool byNamesMode(int argc, char* argv[]) {
    bool successful = true;
    for (int i = 1; i < argc; i++) {
        const char* testName = argv[i];
        if (Test::testsMap.contains(testName)) {
            successful &= Test::testsMap[testName]->start();
        } else {
            successful &= false;
            std::cout << testName << ": wrong test name\n";
        }
    }

    return successful;
}

bool defaultMode() {
    bool successful = true;
    for (Test* test: Test::tests) {
        successful &= test->start();
    }

    return successful;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        return !byNamesMode(argc, argv);
    }

    return !defaultMode();
}
