#include "Test.h"

int main() {
    for (Test* test: Test::tests) {
        test->start();
    }

    return 0;
}
