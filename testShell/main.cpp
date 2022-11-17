#include "Test.h"

int main() {
    std::cout << Test::tests.size() << std::endl;

    for (Test *test: Test::tests) {
        test->run();
    }

    return 0;
}
