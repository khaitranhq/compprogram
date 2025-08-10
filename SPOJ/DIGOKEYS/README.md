# SPOJ DIGOKEYS - Find the Treasure

This repository contains a comprehensive testing framework for the SPOJ DIGOKEYS problem.

## Problem Description

DIGOKEYS is a graph traversal problem where:
- You have N boxes numbered 1 to N
- Box 1 is initially unlocked, others are locked
- Each box i (1 ≤ i ≤ N-1) contains a key that can open some other boxes
- Box N contains treasure (no key)
- Goal: Find minimum steps to reach box N with lexicographically smallest path
- If impossible, output -1

## Files

- `thesis.cpp` - Testing framework that compiles and tests solutions
- `main.cpp` - Working solution for the problem
- `solution2.cpp` - Alternative solution (has formatting issues)
- `verify_test.cpp` - Reference solution for generating test cases
- `tests/` - Directory containing all test cases

## Test Cases

The framework includes 15 comprehensive test cases:

1. **test1** - Multiple test cases with simple paths
2. **test2** - Minimum case (2 boxes)
3. **test3** - Impossible case (cannot reach target)
4. **test4-test6** - Direct path from box 1 to target
5. **test7** - Multiple test cases with different path lengths
6. **test8-test15** - Various edge cases and complex scenarios

### Test Case Categories:

- **Basic connectivity**: Simple paths from start to end
- **Impossible cases**: No path exists to target box
- **Lexicographic ordering**: Multiple paths, test smallest one
- **Edge cases**: Empty connections, single hops, complex graphs
- **Multiple test cases**: Combined scenarios in single input

## Usage

### Compile the testing framework:
```bash
g++ -std=c++17 -O2 -Wall -Wextra -o thesis thesis.cpp
```

### Test a solution:
```bash
./thesis <cpp_file_path>
```

### Examples:
```bash
./thesis main.cpp
./thesis solution2.cpp
./thesis your_solution.cpp
```

## Output Format

The framework provides:
- Compilation status
- Individual test results with timing
- Detailed diff for failed tests
- Summary statistics
- Pass/fail indication

Example output:
```
SPOJ DIGOKEYS Testing Framework
Testing solution: main.cpp
Compiling: g++ -std=c++17 -O2 -Wall -Wextra -o main_test main.cpp
✓ Compilation successful!

==================================================
Running 15 test cases...
==================================================
✓ Test test1: PASSED (2ms)
✓ Test test2: PASSED (1ms)
...
✓ Test test15: PASSED (1ms)

==================================================
TEST SUMMARY
==================================================
Total tests: 15
Passed: 15
Failed: 0
🎉 ALL TESTS PASSED! 🎉
==================================================
```

## Test Case Details

### Input Format:
```
T                    # Number of test cases
N                    # Number of boxes
M1 box1 box2 ...     # Box 1 can open M1 boxes: box1, box2, ...
M2 box1 box2 ...     # Box 2 can open M2 boxes: box1, box2, ...
...
M(N-1) box1 box2 ... # Box N-1 can open M(N-1) boxes
```

### Output Format:
```
q                    # Minimum number of steps (-1 if impossible)
box1 box2 ... boxq   # Path of boxes opened (if solution exists)
```

## Algorithm Notes

The problem requires:
1. **BFS traversal** for shortest path
2. **Lexicographic ordering** by sorting adjacency lists
3. **Path reconstruction** using parent tracking
4. **Early termination** when target is reached

## Testing Your Solution

1. Write your C++ solution for DIGOKEYS
2. Use the testing framework: `./thesis your_solution.cpp`
3. All test cases should pass for a correct solution
4. The framework handles compilation and comparison automatically

## Contributing

To add new test cases:
1. Create `testX.in` with input
2. Generate expected output: `./verify_test_test < testX.in > testX.out`
3. Place both files in `tests/` directory
4. The framework will automatically detect and run new tests