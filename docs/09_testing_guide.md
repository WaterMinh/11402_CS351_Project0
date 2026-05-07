# Testing and CI/CD Guide for Two Sum Project

## 📚 Table of Contents
1. [Overview](#overview)
2. [Test Planning Fundamentals](#test-planning-fundamentals)
3. [Test Case Design](#test-case-design)
4. [Running Local Tests](#running-local-tests)
5. [GitHub Actions CI/CD](#github-actions-cicd)
6. [Test Results Interpretation](#test-results-interpretation)
7. [Advanced Testing Concepts](#advanced-testing-concepts)
8. [Best Practices](#best-practices)
9. [References](#references)

---

## Overview

This guide explains:
- **What**: How to design and execute tests for the Two Sum algorithm
- **Why**: Ensuring correctness, reliability, and robustness
- **How**: Using assertions, test frameworks, and CI/CD pipelines

### Project Structure
```
├── include/
│   └── twosum.h          # Header file (function declaration)
├── src/
│   ├── main.cpp          # Main application
│   └── twosum.cpp        # Implementation (hash table approach)
├── tests/
│   └── test_twosum.cpp   # Test suite
├── docs/
│   ├── 04_test_plan.md   # Detailed test plan
│   └── 09_testing_guide.md  # This file
├── CMakeLists.txt        # Build configuration
└── .github/workflows/
    └── ci.yml            # GitHub Actions workflow
```

---

## Test Planning Fundamentals

### 1. What is a Test Plan?
A **test plan** is a formal document that outlines:
- **Objectives**: What you want to verify
- **Scope**: What will and won't be tested
- **Test cases**: Specific inputs and expected outputs
- **Criteria**: What determines pass/fail
- **Resources**: Tools and people needed

### 2. Why Test Planning Matters
- **Prevents bugs** from reaching production
- **Documents expectations** for future developers
- **Provides traceability** between requirements and tests
- **Ensures comprehensive coverage** of edge cases

### 3. Levels of Testing

#### Unit Testing (What we're doing)
```
┌─────────────────────┐
│ Test Individual     │
│ Functions/Methods   │
│                     │
│ Example: Testing    │
│ twoSum() function   │
└─────────────────────┘
```
- Tests single functions in isolation
- Fastest to execute
- Easiest to debug when failing

#### Integration Testing
```
┌─────────────────────────────┐
│ Test Functions Working      │
│ Together                    │
│                             │
│ Example: twoSum() +         │
│ input validation +          │
│ output formatting           │
└─────────────────────────────┘
```

#### System Testing
```
┌──────────────────────────────┐
│ Test Complete System         │
│                              │
│ Example: Full application    │
│ with user inputs             │
└──────────────────────────────┘
```

---

## Test Case Design

### 1. Test Case Structure
Every test case should include:
```
ID: TC001 (Unique identifier)
Name: Basic case - ascending order
Category: Functional
Input: [2, 7, 11, 15]
Target: 9
Expected Output: [0, 1]
Description: Verifies basic functionality with sorted positive numbers
```

### 2. Test Categories

#### A. Normal/Positive Cases
**Purpose**: Verify expected behavior under normal conditions
```
Input: [2, 7, 11, 15], Target: 9
Expected: [0, 1] where nums[0] + nums[1] = 2 + 7 = 9
Verifies: Algorithm finds correct pair
```

#### B. Edge Cases
**Purpose**: Test boundary conditions

**Empty/Single Element**:
```
Input: [], Target: 5
Expected: [] (no pair possible)
```

**Minimum Size Valid Input**:
```
Input: [1, 2], Target: 3
Expected: [0, 1]
```

#### C. Boundary Cases
**Purpose**: Test extreme values
```
Input: [999999999, 1, 2, 3], Target: 1000000000
Expected: [0, 1]
Verifies: Handles large integers correctly
```

#### D. Negative Cases
**Purpose**: Test when solution doesn't exist
```
Input: [1, 2, 3], Target: 10
Expected: [] (no valid pair)
Verifies: Graceful handling of impossible scenarios
```

#### E. Special Cases
**Purpose**: Test repeated elements, zero, negative numbers

**With Duplicates**:
```
Input: [2, 2, 3, 4], Target: 4
Expected: [0, 1]
Verifies: Correctly handles duplicate values
```

**With Zeros**:
```
Input: [0, 0], Target: 0
Expected: [0, 1]
Verifies: Handles zero correctly
```

**With Negatives**:
```
Input: [-3, 4, 3, 90], Target: 0
Expected: [1, 2] or [0, 1]
Verifies: Works with negative numbers
```

### 3. Equivalence Partitioning
Group test cases by behavior:
```
Partition 1: Valid solution exists (20 test cases)
├── TC1-4: Normal cases
├── TC5-8: Negative numbers
├── TC9-12: Zeros and boundaries
├── TC13-15: Duplicates
├── TC16-17: Large numbers
└── TC18-20: No solution

Each partition tests similar behavior,
reducing need for excessive test cases
```

### 4. Boundary Analysis
Test values at boundaries:
```
Input Range: -10^9 to 10^9
Array Size: 1 to 10,000

Test Cases:
- Minimum valid array: [a, b] (size 2)
- Maximum values: [999999999, 1]
- Minimum values: [-1000000000, 5]
- Mixed: [-1000000000, 500000000, -500000000]
```

---

## Running Local Tests

### 1. Build Configuration

#### Create build directory:
```bash
mkdir build
cd build
```

#### Configure with CMake:
```bash
cmake ..
```

#### Build the project:
```bash
cmake --build .
```

### 2. Execute Tests

#### Run test binary:
```bash
# On Linux/macOS
./test_twosum

# On Windows
test_twosum.exe
```

#### Example Output:
```
=== Two Sum Test Suite ===

--- Section 1: Basic/Normal Cases ---
✓ TC1 PASS: Basic case - ascending order (nums[0]=2, nums[1]=7)
✓ TC2 PASS: Basic case - unordered (nums[1]=2, nums[2]=4)
✓ TC3 PASS: Duplicate values (nums[0]=3, nums[1]=3)
✓ TC4 PASS: Larger array (nums[4]=100, nums[5]=200)

--- Section 2: Negative Numbers ---
✓ TC5 PASS: All negative numbers (nums[2]=-3, nums[4]=-5)
...

=== Test Summary ===
Total Tests: 20
Passed: 20
Failed: 0

✓ All Two Sum tests passed!
```

### 3. Interpreting Test Results

#### ✓ PASS
- Assertion passed
- Returned indices correct
- Sum equals target
- **Action**: No action needed; feature works correctly

#### ✗ FAIL
- Assertion failed
- Wrong indices returned
- Memory error/crash
- **Action**: 
  1. Run single failing test with debugger
  2. Check implementation
  3. Fix and re-run

---

## GitHub Actions CI/CD

### 1. What is GitHub Actions?
Automated testing triggered by:
- 🔄 Push to repository
- 🔀 Pull request creation/update
- ⏰ Schedule (optional)

### 2. Workflow Execution

#### Trigger
```
Developer pushes to main/develop branch
                    ↓
       GitHub Actions workflow runs
                    ↓
Build on multiple platforms:
├── Ubuntu + GCC
├── Ubuntu + Clang
├── macOS + Clang
└── Windows + MSVC
```

#### For each platform:
```
1. Checkout code
2. Install dependencies
3. Configure build (CMake)
4. Compile
5. Run tests
6. Report results
```

### 3. Understanding ci.yml

#### File Location
```
.github/workflows/ci.yml
```

#### Key Sections

**Trigger Events**:
```yaml
on:
  push:
    branches: [ main, develop ]
  pull_request:
    branches: [ main, develop ]
```
Runs tests on push/PR to main or develop

**Matrix Strategy**:
```yaml
strategy:
  matrix:
    include:
      - os: ubuntu-latest
        compiler: gcc
      - os: macos-latest
        compiler: clang
      - os: windows-latest
        compiler: msvc
```
Tests across 4 platform/compiler combinations

**Build Steps**:
```yaml
steps:
  - name: Checkout repository    # Get source code
  - name: Install dependencies   # Setup tools
  - name: Configure CMake        # Prepare build
  - name: Build project          # Compile
  - name: Run tests              # Execute tests
```

### 4. Viewing Results

#### On GitHub:
1. Go to your repository
2. Click "Actions" tab
3. Select recent workflow run
4. View build logs for each platform

#### Status Indicators:
- 🟢 **Green**: All tests passed
- 🔴 **Red**: Tests failed
- 🟡 **Yellow**: In progress

#### Example Workflow Output:
```
✓ Configure CMake (ubuntu-latest, gcc)
✓ Build project (ubuntu-latest, gcc)
✓ Run tests (ubuntu-latest, gcc)
  TC1 PASS, TC2 PASS, ... TC20 PASS

✓ Configure CMake (macos-latest, clang)
✓ Build project (macos-latest, clang)
✓ Run tests (macos-latest, clang)
  TC1 PASS, TC2 PASS, ... TC20 PASS

✓ All workflows completed successfully
```

---

## Test Results Interpretation

### 1. Test Metrics

#### Code Coverage (how much code is tested)
```
Ideal: 80-100%
Our project: ~100% (all lines of twoSum() tested)

Formula:
Coverage = (Lines tested / Total lines) × 100%
```

#### Pass Rate
```
Formula:
Pass Rate = (Passed tests / Total tests) × 100%

Ideal: 100%
Our project: 20/20 = 100%
```

#### Test Count
```
What to measure:
- Total test cases
- Passing tests
- Failing tests
- Skipped tests

Our project:
Total: 20
Passed: 20
Failed: 0
Skip: 0
```

### 2. Failure Analysis

#### When a test fails:

**Step 1: Read error message**
```
✗ TC18 FAIL: No valid pair exists - Assertion failed
Suggests: Function returned data when it shouldn't
```

**Step 2: Check test inputs**
```
Input: [1, 2, 3], Target: 10
Expected: [] (empty)
Actual: [?, ?]
```

**Step 3: Trace implementation**
```
// In twosum.cpp
for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];  // 10 - 1 = 9
    if (map.find(complement) != map.end()) {
        return {map[complement], i};    // Should not reach here
    }
    map[nums[i]] = i;
}
return {};  // Should return this
```

**Step 4: Fix and re-test**
```bash
# After fixing the bug:
cmake --build .
./test_twosum  # Re-run tests
```

---

## Advanced Testing Concepts

### 1. Test-Driven Development (TDD)
**Philosophy**: Write tests before implementation
```
1. Write test
   ├─ RED: Test fails (function doesn't exist)
   
2. Write implementation
   ├─ GREEN: Test passes
   
3. Refactor
   └─ Still GREEN: Tests still pass
```

### 2. Boundary Value Analysis
Test at and around boundaries:
```
Input: {1..10}
├── Below minimum: 0
├── At minimum: 1
├── Just above minimum: 2
├── Just below maximum: 9
├── At maximum: 10
└── Above maximum: 11
```

### 3. Decision Table Testing
Test combinations of conditions:
```
| Condition | True | False |
|-----------|------|-------|
| i != j    | ✓    | ✓     |
| Sum valid | ✓    | ✓     |
| In bounds | ✓    | ✓     |

Combinations tested: 2³ = 8 scenarios
```

### 4. Regression Testing
When bug is fixed, keep test to prevent re-occurrence:
```
Bug Found: Function crashes with empty array
Test Added: checkResult({}, 5)
Fix Applied: Add bounds checking
Regression Test: Ensures fix stays in place
```

### 5. Code Coverage Tools
Measure what code is tested:
```
Tools: gcov (GCC), llvm-cov (Clang)
Usage: cmake --build . && make coverage
Output: HTML report showing untested lines
Goal: >80% coverage
```

---

## Best Practices

### ✅ DO

1. **Write clear test descriptions**
   ```cpp
   checkResult({0, 0}, 0, 9, "Two zeros");  // Good
   checkResult({0, 0}, 0, 9, "test");       // Bad
   ```

2. **Test one thing per test case**
   ```cpp
   // Good: Tests only duplicates
   checkResult({3, 3}, 6, 3, "Duplicate values");
   
   // Bad: Tests multiple things
   checkResult({3, 3}, 6, 3, "Duplicates and zero cases");
   ```

3. **Use meaningful variable names**
   ```cpp
   // Good
   int expected_index = result[0];
   
   // Bad
   int x = result[0];
   ```

4. **Document edge cases**
   ```cpp
   // Test why this matters
   // Hash table must handle negative complements
   checkResult({-3, 4, 3, 90}, 0, 7, "Result equals zero");
   ```

5. **Keep tests independent**
   ```cpp
   // ✓ Each test is standalone
   checkResult({2, 7, 11, 15}, 9, 1, "Case 1");
   checkResult({3, 2, 4}, 6, 2, "Case 2");
   
   // ✗ Tests depending on each other
   // (avoid state sharing)
   ```

### ❌ DON'T

1. **Don't test implementation details**
   ```cpp
   // ✗ Wrong: Testing internal map structure
   assert(map.size() == 2);
   
   // ✓ Right: Testing only observable behavior
   assert(nums[i] + nums[j] == target);
   ```

2. **Don't ignore test failures**
   ```cpp
   // ✗ Wrong: Commented out failing test
   // checkResult({1, 2, 3}, 10, 18, "No solution");
   
   // ✓ Right: Fix the implementation or test
   checkResult({1, 2, 3}, 10, 18, "No solution");
   ```

3. **Don't hardcode test data**
   ```cpp
   // ✗ Hard to maintain
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   
   // ✓ Clear intent
   std::vector<int> nums = {1, 2, 3};
   checkResult(nums, 5, 1, "Basic case");
   ```

4. **Don't have tests that sometimes pass, sometimes fail**
   ```cpp
   // ✗ Non-deterministic (bad)
   int random_target = rand() % 100;
   
   // ✓ Deterministic (good)
   int fixed_target = 50;
   ```

---

## References

### Testing Concepts
- [Wikipedia: Software Testing](https://en.wikipedia.org/wiki/Software_testing)
- [ISTQB Testing Fundamentals](https://www.istqb.org/)

### C++ Testing
- [Google Test Framework](https://github.com/google/googletest)
- [Catch2 Testing Framework](https://github.com/catchorg/Catch2)

### GitHub Actions
- [GitHub Actions Documentation](https://docs.github.com/en/actions)
- [GitHub Actions - C++ CI/CD](https://github.com/actions/starter-workflows/blob/main/ci/cmake.yml)

### CMake
- [CMake Official Documentation](https://cmake.org/cmake/help/latest/)
- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

### The Two Sum Problem
- [LeetCode - Two Sum](https://leetcode.com/problems/two-sum/)
- [Geeks for Geeks - Two Sum](https://www.geeksforgeeks.org/two-sum-problem-using-hash-map/)

---

## Quick Reference

### Commands
```bash
# Build
mkdir build && cd build
cmake ..
cmake --build .

# Test locally
./test_twosum

# Clean
rm -rf build
```

### Test Categories Used
- **Functional**: Normal expected cases (TC1-4)
- **Negative Numbers**: Negative inputs (TC5-8)
- **Zero Cases**: Tests with zero (TC9-12)
- **Duplicates**: Repeated values (TC13-15)
- **Large Numbers**: Extreme values (TC16-17)
- **No Solution**: Impossible cases (TC18-20)

### Expected Results
```
Total Tests: 20
All Passing: ✓
Build Status: All platforms passing
Coverage: ~100%
```

---

## Next Steps for Learning

1. **Understand the algorithm**: Study hash table approach in twosum.cpp
2. **Run tests locally**: Execute the test suite and understand output
3. **Add new test cases**: Create additional test cases for edge cases
4. **Monitor GitHub Actions**: Watch workflow run on your push/PR
5. **Advanced testing**: Explore frameworks like Google Test
6. **Performance testing**: Add timing benchmarks for large inputs

Good luck with your testing! 🚀
