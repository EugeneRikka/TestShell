#ifndef CHECK_H
#define CHECK_H

#include <iostream>

struct Check {
    Check() {
        puts("Check constructed");
    }

    Check(const Check &other) {
        puts("Check copied");
    }

    Check(const Check &&other) noexcept {
        puts("Check moved");
    }

    Check &operator=(const Check &other) {
        puts("Check copied by =");
        return *this;
    }

    Check &operator=(Check &&other) noexcept {
        puts("Check moved by =");
    }
};

#endif //CHECK_H
