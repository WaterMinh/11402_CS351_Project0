#include <iostream>
#include <vector>
#include "../include/twosum.h"

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    auto result = twoSum(nums, target);

    if (result.size() == 2 && nums[result[0]] + nums[result[1]] == target) {
        std::cout << "Test passed\n";
    } else {
        std::cout << "Test failed\n";
    }

    return 0;
}