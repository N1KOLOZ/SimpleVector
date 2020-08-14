#include "simple_vector.h"
#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void TestConstruction() {
    SimpleVector<int> empty;
    ASSERT_EQUAL(empty.Size(), 0u);
    ASSERT_EQUAL(empty.Capacity(), 0u);
    ASSERT(empty.begin() == empty.end());

    SimpleVector<string> five_strings(5);
    ASSERT_EQUAL(five_strings.Size(), 5u);
    ASSERT(five_strings.Size() <= five_strings.Capacity());
    for (auto& item : five_strings) {
        ASSERT(item.empty());
    }
    five_strings[2] = "Hello";
    ASSERT_EQUAL(five_strings[2], "Hello");
}

void TestPushBack() {
    SimpleVector<int> v;
    for (int i = 10; i >= 1; --i) {
        v.PushBack(i);
        ASSERT(v.Size() <= v.Capacity());
    }
    sort(begin(v), end(v));

    const vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ASSERT_EQUAL(v.Size(), expected.size());
    ASSERT(equal(begin(v), end(v), begin(expected)));
}

void TestCopyConstructorAndAssignmentOperator() {
    SimpleVector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.PushBack(i);
    }
    SimpleVector<int> v_test = v;

    SimpleVector<int> v_test2;
    v_test2 = v;

    const vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ASSERT(std::equal(begin(v_test), end(v_test), begin(expected)));
    ASSERT(std::equal(begin(v_test2), end(v_test2), begin(expected)));
}

class StringNonCopyable : public string {
public:
    using string::string;
    StringNonCopyable(string&& other) : string(move(other)) {}
    StringNonCopyable(const StringNonCopyable&) = delete;
    StringNonCopyable(StringNonCopyable&&) = default;
    StringNonCopyable& operator=(const StringNonCopyable&) = delete;
    StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

void TestNoCopy() {
    SimpleVector<StringNonCopyable> strings;
    const int SIZE = 10;
    for (int i = 0; i < SIZE; ++i) {
        strings.PushBack(StringNonCopyable(to_string(i)));
    }
    for (int i = 0; i < SIZE; ++i) {
        ASSERT_EQUAL(strings[i], to_string(i));
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestConstruction);
    RUN_TEST(tr, TestPushBack);
    RUN_TEST(tr, TestCopyConstructorAndAssignmentOperator);
    RUN_TEST(tr, TestNoCopy);

    return 0;
}