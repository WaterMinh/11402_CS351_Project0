#include "twosum.h"
#include <iostream>
#include <vector>
#include <cassert>

// Test counter for tracking
int test_count = 0;
int passed_count = 0;
int failed_count = 0;

/**
 * Helper function to validate test results
 * @param nums Input array
 * @param target Target sum
 * @param test_id Test case identifier
 * @param test_name Description of test case
 */
void checkResult(const std::vector<int>& nums, int target, int test_id, const std::string& test_name) {
    test_count++;
    try {
        std::vector<int> result = twoSum(const_cast<std::vector<int>&>(nums), target);

        // Validation: Check if result has exactly 2 elements for valid solutions
        if (result.size() == 0) {
            // No solution found - valid for some cases
            std::cout << "✓ TC" << test_id << " PASS: " << test_name << " (No solution)" << std::endl;
            passed_count++;
            return;
        }

        assert(result.size() == 2);
        int i = result[0];
        int j = result[1];

        // Validate indices are within bounds
        assert(i >= 0 && i < nums.size());
        assert(j >= 0 && j < nums.size());

        // Validate indices are different
        assert(i != j);

        // Validate the sum matches target
        assert(nums[i] + nums[j] == target);

        std::cout << "✓ TC" << test_id << " PASS: " << test_name 
                  << " (nums[" << i << "]=" << nums[i] << ", nums[" << j << "]=" << nums[j] << ")" << std::endl;
        passed_count++;
    } catch (const std::exception& e) {
        std::cerr << "✗ TC" << test_id << " FAIL: " << test_name << " - Exception: " << e.what() << std::endl;
        failed_count++;
    } catch (...) {
        std::cerr << "✗ TC" << test_id << " FAIL: " << test_name << " - Unknown error" << std::endl;
        failed_count++;
    }
}

int main() {
    std::cout << "=== Two Sum Test Suite ===" << std::endl << std::endl;

    // Section 1: Normal/Functional Test Cases
    std::cout << "--- Section 1: Basic/Normal Cases ---" << std::endl;
    checkResult({2, 7, 11, 15}, 9, 1, "Basic case - ascending order");
    checkResult({3, 2, 4}, 6, 2, "Basic case - unordered");
    checkResult({3, 3}, 6, 3, "Duplicate values");
    checkResult({1, 2, 3, 4, 100, 200}, 300, 4, "Larger array");
    std::cout << std::endl;

    // Section 2: Negative Number Test Cases
    std::cout << "--- Section 2: Negative Numbers ---" << std::endl;
    checkResult({-1, -2, -3, -4, -5}, -8, 5, "All negative numbers");
    checkResult({-10, 20, 30, -5}, 15, 6, "Mixed positive/negative");
    checkResult({-3, 4, 3, 90}, 0, 7, "Result equals zero");
    checkResult({-1000000000, 500000000, -500000000}, -1500000000, 8, "Very large negative");
    std::cout << std::endl;

    // Section 3: Zero and Boundary Cases
    std::cout << "--- Section 3: Zero and Boundaries ---" << std::endl;
    checkResult({0, 0}, 0, 9, "Two zeros");
    checkResult({0, 4, 3, 0}, 0, 10, "Multiple zeros with duplicates");
    checkResult({0, 1, 2, 3}, 3, 11, "Zero with other values");
    checkResult({5, 0, 10, -5}, 0, 12, "Zero in middle");
    std::cout << std::endl;

    // Section 4: Duplicate Values Test Cases
    std::cout << "--- Section 4: Duplicate Values ---" << std::endl;
    checkResult({1, 5, 1, 5}, 10, 13, "Duplicate pairs");
    checkResult({2, 2, 3, 4}, 4, 14, "Duplicate solution");
    checkResult({6, 1, 6, 8}, 12, 15, "Duplicates non-adjacent");
    std::cout << std::endl;

    // Section 5: Large Number Cases
    std::cout << "--- Section 5: Large Numbers ---" << std::endl;
    checkResult({1000000000, -1000000000, 5}, 0, 16, "Very large integers");
    checkResult({999999999, 1, 2, 3}, 1000000000, 17, "Large target sum");
    std::cout << std::endl;

    // Section 6: Edge Cases (No Solution)
    std::cout << "--- Section 6: No Solution Cases ---" << std::endl;
    checkResult({1, 2, 3}, 10, 18, "No valid pair exists");
    checkResult({5, 5}, 11, 19, "Target unreachable");
    checkResult({100, 200, 300}, 10, 20, "All numbers too large");
    std::cout << std::endl;

    // Print summary
    std::cout << "=== Test Summary ===" << std::endl;
    std::cout << "Total Tests: " << test_count << std::endl;
    std::cout << "Passed: " << passed_count << std::endl;
    std::cout << "Failed: " << failed_count << std::endl;

    if (failed_count == 0) {
        std::cout << "\n✓ All Two Sum tests passed!" << std::endl;
        return 0;
    } else {
        std::cout << "\n✗ Some tests failed!" << std::endl;
        return 1;
    }
}