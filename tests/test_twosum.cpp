#include "twosum.h"
#include <iostream>
#include <vector>
#include <cassert>

void checkResult(std::vector<int> nums, int target) {
    std::vector<int> result = twoSum(nums, target);

    assert(result.size() == 2);

    int i = result[0];
    int j = result[1];

    assert(i >= 0 && i < nums.size());
    assert(j >= 0 && j < nums.size());
    assert(i != j);
    assert(nums[i] + nums[j] == target);
}

int main() {
    checkResult({2, 7, 11, 15}, 9);
    checkResult({3, 2, 4}, 6);
    checkResult({3, 3}, 6);

    checkResult({-1, -2, -3, -4, -5}, -8);
    checkResult({-10, 20, 30, -5}, 15);
    checkResult({-3, 4, 3, 90}, 0);

    checkResult({0, 4, 3, 0}, 0);
    checkResult({0, 1, 2, 3}, 3);
    checkResult({5, 0, 10, -5}, 0);

    checkResult({1, 5, 1, 5}, 10);
    checkResult({2, 2, 3, 4}, 4);
    checkResult({6, 1, 6, 8}, 12);

    checkResult({1000000000, -1000000000, 5}, 0);
    checkResult({999999999, 1, 2, 3}, 1000000000);
    checkResult({-1000000000, 500000000, -500000000}, -1500000000);

    checkResult({1, 2, 3, 4, 100, 200}, 300);
    checkResult({10, 20, 30, 40, 50}, 90);

    std::cout << "All Two Sum tests passed!" << std::endl;
    return 0;
}