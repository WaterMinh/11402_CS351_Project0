# Test Plan: Two Sum Implementation

## 1. Objective
Verify correctness, robustness, and performance of the Two Sum algorithm across various input scenarios and edge cases.

## 2. Test Strategy

### 2.1 Test Categories
- **Functional Tests**: Verify correct behavior for valid inputs
- **Edge Case Tests**: Boundary conditions and special scenarios
- **Negative Tests**: Invalid or no-solution scenarios
- **Performance Tests**: Algorithm efficiency (Optional for future)

### 2.2 Test Levels
- **Unit Tests**: Individual function behavior
- **Integration Tests**: Function with different data types
- **System Tests**: Full build and execution pipeline (via GitHub Actions)

## 3. Test Cases

### 3.1 Normal/Functional Test Cases

| ID  | Category | Input | Target | Expected Output | Description |
|-----|----------|-------|--------|-----------------|-------------|
| TC1 | Basic    | [2,7,11,15] | 9 | [0,1] | Simple case, ascending order |
| TC2 | Basic    | [3,2,4] | 6 | [1,2] | Unordered array |
| TC3 | Basic    | [3,3] | 6 | [0,1] | Duplicate values |
| TC4 | Basic    | [1,2,3,4,100,200] | 300 | [4,5] | Larger array |

### 3.2 Negative Number Test Cases

| ID  | Category | Input | Target | Expected Output | Description |
|-----|----------|-------|--------|-----------------|-------------|
| TC5 | Negative | [-1,-2,-3,-4,-5] | -8 | [2,4] | All negative values |
| TC6 | Negative | [-10,20,30,-5] | 15 | [1,3] | Mixed positive/negative |
| TC7 | Negative | [-3,4,3,90] | 0 | [0,1] or [1,2] | Result equals zero |
| TC8 | Negative | [-1000000000, 500000000, -500000000] | -1500000000 | [0,1] | Very large negative |

### 3.3 Zero and Boundary Cases

| ID  | Category | Input | Target | Expected Output | Description |
|-----|----------|-------|--------|-----------------|-------------|
| TC9 | Zero | [0,0] | 0 | [0,1] | Two zeros |
| TC10 | Zero | [0,4,3,0] | 0 | [0,3] or [2,1] | Multiple zeros with duplicates |
| TC11 | Boundary | [0,1,2,3] | 3 | [0,3] or [1,2] | Zero with other values |
| TC12 | Boundary | [5,0,10,-5] | 0 | [1,3] | Zero in middle |

### 3.4 Duplicate Values Test Cases

| ID  | Category | Input | Target | Expected Output | Description |
|-----|----------|-------|--------|-----------------|-------------|
| TC13 | Duplicates | [1,5,1,5] | 10 | [1,3] | Duplicate pairs |
| TC14 | Duplicates | [2,2,3,4] | 4 | [0,1] | Duplicate solution |
| TC15 | Duplicates | [6,1,6,8] | 12 | [0,2] or [1,3] | Duplicates non-adjacent |

### 3.5 Large Number Cases

| ID  | Category | Input | Target | Expected Output | Description |
|-----|----------|-------|--------|-----------------|-------------|
| TC16 | Large | [1000000000, -1000000000, 5] | 0 | [0,1] | Very large integers |
| TC17 | Large | [999999999, 1, 2, 3] | 1000000000 | [0,1] | Large target sum |

### 3.6 Edge Cases (No Solution)

| ID  | Category | Input | Target | Expected Output | Description |
|-----|----------|-------|--------|-----------------|-------------|
| TC18 | No Solution | [1,2,3] | 10 | [] | No valid pair exists |
| TC19 | No Solution | [5,5] | 11 | [] | Target unreachable |
| TC20 | No Solution | [100,200,300] | 10 | [] | All numbers too large |

## 4. Expected Behavior

### 4.1 Return Value Requirements
- **Valid Solution**: Return a vector with exactly 2 indices `[i, j]` where:
  - `nums[i] + nums[j] == target`
  - `i != j`
  - `0 <= i < nums.size()` and `0 <= j < nums.size()`
  - Index order: `i < j` (if applicable)

- **No Solution**: Return empty vector `[]`

### 4.2 Constraints
- Input array size: 2 to 10,000 elements
- Integer range: -10^9 to 10^9
- Exactly one solution guaranteed for test cases with solutions

## 5. Test Execution Criteria

### Pass Criteria
- ✅ All assertions pass
- ✅ No runtime errors (segmentation faults, etc.)
- ✅ Correct indices returned for all test cases
- ✅ Returned indices satisfy the constraint `nums[i] + nums[j] == target`
- ✅ No memory leaks or undefined behavior

### Fail Criteria
- ❌ Any assertion fails
- ❌ Runtime error or crash
- ❌ Incorrect indices returned
- ❌ Constraint violation (wrong sum, same indices, out of bounds)

## 6. Testing Tools & Frameworks

### 6.1 Current Approach
- **Framework**: C++ `cassert` library
- **Build System**: CMake (to be configured)
- **CI/CD**: GitHub Actions

### 6.2 Future Enhancements
- Adopt Google Test Framework (gtest) for more advanced testing
- Add code coverage analysis
- Performance benchmarking with large datasets

## 7. Test Execution Procedure

### 7.1 Local Testing
```bash
# Build the project
mkdir build && cd build
cmake ..
make

# Run tests
./bin/test_twosum
```

### 7.2 Automated Testing (GitHub Actions)
- Automatic testing on every push
- Cross-platform testing (Linux, macOS, Windows)
- Build verification and test reporting

## 8. Test Data Management

### 8.1 Test Data Sources
- Manually created test cases covering requirements
- LeetCode reference: https://leetcode.com/problems/two-sum/
- Custom edge cases based on implementation specifics

### 8.2 Test Case Maintenance
- Add new test cases when bugs are discovered
- Review and refactor test cases periodically
- Document reasons for each test case inclusion