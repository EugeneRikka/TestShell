#include "Test.h"

int main() {
    for (Test* test: Test::tests) {
        test->init();
        test->run();
    }

    return 0;
}
