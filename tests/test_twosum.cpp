#include "twosum.h"
#include <iostream>
#include <vector>
#include <cassert>

void checkResult(std::vector<int> nums, int target, int expectedA, int expectedB) {
    std::vector<int> result = twoSum(nums, target);

    assert(result.size() == 2);
    assert(result[0] == expectedA);
    assert(result[1] == expectedB);
}

int main() {
    // Basic cases
    checkResult({2, 7, 11, 15}, 9, 0, 1);
    checkResult({3, 2, 4}, 6, 1, 2);
    checkResult({3, 3}, 6, 0, 1);

    // Negative numbers
    checkResult({-1, -2, -3, -4, -5}, -8, 2, 4);
    checkResult({-10, 20, 30, -5}, 15, 1, 3);
    checkResult({-3, 4, 3, 90}, 0, 0, 2);

    // Zero cases
    checkResult({0, 4, 3, 0}, 0, 0, 3);
    checkResult({0, 1, 2, 3}, 3, 0, 3);
    checkResult({5, 0, 10, -5}, 0, 0, 3);

    // Duplicate values
    checkResult({1, 5, 1, 5}, 10, 1, 3);
    checkResult({2, 2, 3, 4}, 4, 0, 1);
    checkResult({6, 1, 6, 8}, 12, 0, 2);

    // Large numbers
    checkResult({1000000000, -1000000000, 5}, 0, 0, 1);
    checkResult({999999999, 1, 2, 3}, 1000000000, 0, 1);
    checkResult({-1000000000, 500000000, -500000000}, -1500000000, 0, 2);

    // Solution near the end
    checkResult({1, 2, 3, 4, 100, 200}, 300, 4, 5);
    checkResult({10, 20, 30, 40, 50}, 90, 3, 4);

    std::cout << "All Two Sum tests passed!" << std::endl;
    return 0;
}