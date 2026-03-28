# Software Design Specification (SDS)

## Architecture

The system is divided into:
- Header file (include/)
- Implementation file (src/)
- Test file (tests/)

## Algorithm Design

The solution uses a hash map:

1. Iterate through the array
2. For each element, compute complement = target - current value
3. Check if complement exists in hash map
4. If yes, return indices
5. Otherwise, store current value and index

## Data Structures

- unordered_map<int, int> for fast lookup