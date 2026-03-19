# Two Sum

# Project Overview
Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to the target. You may assume each input has exactly one solution, and you cannot use the same element twice.

# Implementation Scenarios
You must implement two solutions:

TwoSumArray: Brute force approach using nested loops
TwoSumHashTable: Optimized approach using a hash table

# Requirements

## Functional Requirements
- **Input Validation**: The function must accept an array of integers (`nums`) and an integer (`target`). Assume `nums` has at least 2 elements and at most 10^4 elements, with values ranging from -10^9 to 10^9. `target` ranges from -10^9 to 10^9.
- **Output**: Return a list or array of two indices (0-based) where the elements at those positions sum to `target`. Indices must be in ascending order (e.g., [i, j] where i < j).
- **Uniqueness**: Each element can be used only once. There is exactly one solution per input.
- **TwoSumArray Implementation**: Use nested loops to check all pairs. Time complexity: O(n^2), Space complexity: O(1).
- **TwoSumHashTable Implementation**: Use a hash map to store complements. Time complexity: O(n), Space complexity: O(n).

## Non-Functional Requirements
- **Performance**: TwoSumHashTable must handle up to 10^4 elements efficiently.
- **Language**: Implement in Python (or specify if different).
- **Edge Cases**: Handle arrays with negative numbers, zeros, and duplicates (but ensure unique indices).

## Testing Requirements
- **Unit Tests**: Write tests for normal cases, edge cases (e.g., [2,7,11,15], target=9 → [0,1]; [3,3], target=6 → [0,1]; [-1,-2,-3,-4,-5], target=-8 → [2,4]).
- **Coverage**: Ensure tests cover both implementations and fail cases (e.g., no solution, though problem assumes one exists).
- **Tools**: Use pytest or unittest for testing.

