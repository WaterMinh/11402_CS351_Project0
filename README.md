# Project 0 – Two Sum (C++)

## 📌 Overview

This repository contains the implementation of Project 0 for CS351, focusing on solving the Two Sum problem using both brute-force and optimized approaches.

The project demonstrates algorithmic thinking, performance comparison, and clean C++ project structure.

## 📌 Objective
The goal of this project is to implement and compare two different approaches to solve the classic "Two Sum" problem, focusing on algorithmic complexity and performance.

---

## 🧠 Problem Description
Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to the target.

- Each input has exactly one solution.
- The same element cannot be used twice.
- The result must be returned in ascending index order.

---

## ⚙️ Implementations

### 🔹 1. TwoSumArray (Brute Force)
- Uses nested loops to check all pairs.
- Time Complexity: **O(n²)**
- Space Complexity: **O(1)**

---

### 🔹 2. TwoSumHashTable (Optimized)
- Uses a hash map to store complements.
- Time Complexity: **O(n)**
- Space Complexity: **O(n)**

---

## 📂 Project Structure

```
11402_CS351_Project0/
│
├── src/ # Source code
├── include/ # Header files
├── tests/ # Unit tests
├── docs/ # Reports & documentation
├── .github/ # CI workflow
└── README.md
```

---

## 🛠 Requirements

### Functional Requirements
- Input: integer array `nums` and integer `target`
- Output: two indices `[i, j]` such that `nums[i] + nums[j] = target`
- Indices must be in ascending order
- Exactly one solution exists

---

### Non-Functional Requirements
- Must handle up to **10⁴ elements efficiently**
- Must be implemented in **C++**
- Must handle edge cases:
  - Negative numbers
  - Duplicates
  - Zeros

---

## 🧪 Testing

### Example Test Cases
- `[2,7,11,15], target=9 → [0,1]`
- `[3,3], target=6 → [0,1]`
- `[-1,-2,-3,-4,-5], target=-8 → [2,4]`

### Coverage
- Normal cases
- Edge cases
- Both implementations

---

## ▶️ How to Run

### Run unit tests
```bash
g++ -Iinclude src/twosum.cpp tests/test_twosum.cpp -o test
./test
