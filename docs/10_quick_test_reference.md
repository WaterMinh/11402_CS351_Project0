# Quick Start: Running Tests

## 🚀 One-Minute Quick Start

### Build and Run Tests
```bash
# Clone/Enter repository
cd /Users/minhly/VS\ Code/11402_CS351_Project0

# Build
mkdir build && cd build
cmake ..
cmake --build .

# Test
./test_twosum

# Expected output: "✓ All Two Sum tests passed!"
```

---

## 📋 Full Testing Workflow

### 1. Local Development & Testing

```bash
# Setup
mkdir build
cd build
cmake ..
cmake --build .

# Run tests
./test_twosum

# View results: PASS = ✓, FAIL = ✗
```

### 2. GitHub Automatic Testing

**What happens automatically:**
1. You push code to `main` or `develop`
2. GitHub Actions workflow starts
3. Tests run on 4 platform/compiler combinations
4. Results visible in GitHub "Actions" tab

**To see results:**
- Go to GitHub repository
- Click "Actions" tab
- Click latest workflow run
- See test results for each platform

---

## ✅ Test Results Checklist

### Success Criteria
- [ ] Total Tests: 20
- [ ] Passed: 20
- [ ] Failed: 0
- [ ] All assertions pass
- [ ] No memory errors
- [ ] CI workflow green on all platforms

### If Tests Fail
1. Run locally: `./test_twosum`
2. Check error message
3. Verify input/expected output
4. Fix implementation
5. Re-run: `cmake --build . && ./test_twosum`

---

## 📁 Key Files

| File | Purpose |
|------|---------|
| [docs/04_test_plan.md](04_test_plan.md) | Detailed test cases (20 test cases across 6 categories) |
| [docs/09_testing_guide.md](09_testing_guide.md) | Learning guide (comprehensive testing concepts) |
| [tests/test_twosum.cpp](../../tests/test_twosum.cpp) | Test implementation |
| [CMakeLists.txt](../../CMakeLists.txt) | Build configuration |
| [.github/workflows/ci.yml](../../.github/workflows/ci.yml) | GitHub Actions configuration |

---

## 🧪 Test Categories

### 1. Basic Cases (TC1-4)
Normal expected inputs: ascending, unordered, duplicates, large arrays

### 2. Negative Numbers (TC5-8)
All negative, mixed, negative results, very large negatives

### 3. Zero Cases (TC9-12)
Two zeros, zeros with duplicates, zero with others, zero in middle

### 4. Duplicates (TC13-15)
Duplicate pairs, duplicate solutions, non-adjacent duplicates

### 5. Large Numbers (TC16-17)
Extreme integer values, overflow boundaries

### 6. No Solution (TC18-20)
Impossible targets, unreachable sums, all numbers too large

---

## 🔍 Debugging Failed Tests

### Example: Test Fails
```bash
✗ TC18 FAIL: No valid pair exists - Assertion failed
```

### Steps to Fix

**Step 1**: Identify which test failed (TC18)

**Step 2**: Find test case in [test_twosum.cpp](../../tests/test_twosum.cpp)
```cpp
checkResult({1, 2, 3}, 10, 18, "No valid pair exists");
```

**Step 3**: Understand inputs/expected
- Input: [1, 2, 3]
- Target: 10
- Expected: Empty vector []
- Why: No two numbers sum to 10

**Step 4**: Check implementation in [twosum.cpp](../../src/twosum.cpp)
- Verify it returns {} when no solution exists

**Step 5**: Fix and retest
```bash
# Edit src/twosum.cpp
# Then:
cmake --build .
./test_twosum
```

---

## 📊 Understanding Test Output

### Console Output Breakdown
```
=== Two Sum Test Suite ===                    # Header

--- Section 1: Basic/Normal Cases ---         # Test category
✓ TC1 PASS: ...                               # Passing test
✗ TC18 FAIL: ...                              # Failing test (if any)

=== Test Summary ===                          # Summary section
Total Tests: 20
Passed: 20
Failed: 0
```

### Passing Indicators
```
✓ All Two Sum tests passed!       # Success message
Exit code: 0                       # Success code
```

### Failing Indicators
```
✗ Some tests failed!               # Failure message
Exit code: 1                       # Failure code
Assertion details in output        # Debug info
```

---

## 🛠️ Common Issues & Solutions

| Issue | Solution |
|-------|----------|
| CMake not found | `brew install cmake` or use apt-get |
| Build fails | Check `include/twosum.h` syntax |
| Tests not found | Verify `tests/test_twosum.cpp` exists |
| Wrong output | Check `src/twosum.cpp` implementation |
| GitHub Actions fails | Push to main/develop, check Actions tab |

---

## 📈 Performance Notes

### Current Implementation
- **Algorithm**: Hash Table (Hash Map)
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)
- **Best for**: Fast lookup, worst case acceptable

### Test Performance
- **Test Count**: 20 tests
- **Execution Time**: < 1 second locally
- **CI/CD Time**: ~2-5 minutes (all platforms)

---

## 🔗 Related Documentation

- [Main README](../../README.md) - Project overview
- [Test Plan](04_test_plan.md) - Detailed test cases
- [Testing Guide](09_testing_guide.md) - Comprehensive learning resource
- [SDS (Software Design Specification)](03_SDS.md) - Algorithm details

---

## 💡 Pro Tips

1. **Run tests after every change**
   ```bash
   cmake --build . && ./test_twosum
   ```

2. **View test file to understand test structure**
   ```bash
   cat tests/test_twosum.cpp | head -50
   ```

3. **Add your own test cases** in `test_twosum.cpp`
   ```cpp
   checkResult({your_nums}, your_target, test_id, "Your description");
   ```

4. **Monitor GitHub Actions** for CI/CD status
   - Automatic after every push
   - Tests 4 platform/compiler combinations
   - Green badge = All tests passed

5. **Study the implementation** while tests pass
   - Understand hash table approach
   - Trace through with test inputs
   - See why each test case matters

---

**Last Updated**: May 2026
**Test Version**: 2.0 (Comprehensive with 20 test cases)
**Status**: ✅ Production Ready
