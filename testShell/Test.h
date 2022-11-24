#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <any>

class TestField {
    int currentValueIndex = 0;

public:
    std::vector<std::any> values;

    const std::any &current() const {
        return values[currentValueIndex];
    }

    bool nextValue() {
        if (++currentValueIndex == values.size()) {
            return false;
        }

        return true;
    }

    void resetCurrent() {
        currentValueIndex = 0;
    }
};

enum CasesType {
    None, NoFields, Pairs, Combinations
};

class TestData {
    CasesType casesType = None;

    std::map<std::string, TestField> data;

public:
    void setCasesType(CasesType value) {
        casesType = value;
    }

    bool isCasesTypeSet() {
        return casesType != None;
    }

    template <class T>
    void registerField(const std::string &name, const std::initializer_list<T> &values) {
        if (data.contains(name)) {
            throw std::runtime_error("field \"" + name + "\" already registered");
        }

        std::vector<std::any> &FieldValues = data[name].values;
        for (const auto &value: values) {
            FieldValues.emplace_back(std::move(value));
        }
    }

    template <class T>
    T getField(const std::string &name) const {
        return std::any_cast<T>(data.at(name).current());
    }

    bool nextCase() {
        switch (casesType) {
            case NoFields: {
                return false;
            }

            case Pairs:
                for (auto &[name, testField]: data) {
                    bool isNext = testField.nextValue();
                    if (!isNext) {
                        return false;
                    }
                }

                return true;

            case Combinations:
                for (auto &[name, testField]: data) {
                    bool isNext = testField.nextValue();
                    if (isNext) {
                        return true;
                    } else {
                        testField.resetCurrent();
                    }
                }

                return false;

            default:
                return false;
        }
    }
};

class Test {
private:
    std::string name;

protected:
    TestData testData;

    Test(const char* name) : name(name) {
        tests.push_back(this);
    }

    virtual void init() = 0;
    virtual std::string info() = 0;
    virtual void run() = 0;

public:
    static std::vector<Test*> tests;

    Test(const Test &other) = delete;
    Test &operator=(const Test &other) = delete;
    Test(const Test &&other) = delete;
    Test &operator=(const Test &&other) = delete;

    void start() {
        try {
            init();
        } catch (const std::runtime_error &error) {
            std::cout << name + ". Initialize error: " << error.what() << '\n';
            return;
        }

        if (!testData.isCasesTypeSet()) {
            std::cout << name + ". testData cases type must be set\n";
            return;
        }

        do {
            bool successful = true;

            try {
                run();
            } catch (const std::runtime_error &error) {
                successful = false;
                std::cout << name + " (" << info() << "). Failed, reason - " << error.what() << '\n';
            }

            if (successful) {
                std::cout << name + " (" << info() << "). OK\n";
            }
        } while (testData.nextCase());
    }
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
protected:                               \
    void init() override;                \
    std::string info() override;         \
    void run() override;                 \
};                                       \
                                         \
TestName TestName::obj##TestName;