# SPOJ DIGOKEYS Test Case Descriptions

## Test Case Overview

| Test | Description | Expected Result | Purpose |
|------|-------------|-----------------|---------|
| test1 | Two test cases: 3-box and 4-box scenarios | Paths: 1→2→3 and 1→3→4 | Basic BFS and multi-test handling |
| test2 | Minimal case: 2 boxes | Direct path: 1→2 | Edge case: minimum problem size |
| test3 | Impossible case: box 1 can't reach any others | -1 | Testing unreachable scenarios |
| test4 | 5 boxes with direct path to target | Direct path: 1→5 | Testing immediate solution |
| test5 | 6 boxes with direct path to target | Direct path: 1→6 | Testing immediate solution |
| test6 | 7 boxes with direct path to target | Direct path: 1→7 | Testing immediate solution |
| test7 | Two test cases: 4-box chain and 8-box direct | Paths: 1→2→3→4 and 1→8 | Chain traversal vs direct |
| test8 | 10 boxes with direct path | Direct path: 1→10 | Large direct path |
| test9 | Three test cases: simple, impossible, multi-hop | Mixed results | Comprehensive scenario testing |
| test10 | 6 boxes with indirect path | Direct path: 1→6 | Testing path finding |
| test11 | 6 boxes with direct path | Direct path: 1→6 | Additional path validation |
| test12 | 7 boxes with direct path | Direct path: 1→7 | Additional path validation |
| test13 | 8 boxes requiring 2 hops | Path: 1→4→8 | Testing multi-hop pathfinding |
| test14 | 9 boxes with direct path | Direct path: 1→9 | Large graph direct path |
| test15 | Two test cases: 5-box and 10-box | Paths: 1→2→5 and 1→10 | Multi-hop vs direct scenarios |

## Detailed Test Case Analysis

### test1: Basic Multi-Test Case
```
Input: 2 test cases
- Test 1: 3 boxes, path 1→2→3 (2 steps)
- Test 2: 4 boxes, path 1→3→4 (2 steps)
Purpose: Verify basic BFS and multiple test case handling
```

### test2: Minimum Size Case
```
Input: 1 test case with 2 boxes
- Box 1 can open box 2
- Direct path: 1→2 (1 step)
Purpose: Test minimum valid problem size
```

### test3: Impossible Case
```
Input: 1 test case with 3 boxes
- Box 1 cannot open any other boxes
- No path to box 3 exists
Purpose: Test unreachable target detection
```

### test4-test6: Direct Path Cases
```
Purpose: Test scenarios where box 1 can directly open the target box
Validates immediate solution detection
```

### test7: Mixed Complexity
```
Input: 2 test cases
- Test 1: Chain path requiring 3 steps
- Test 2: Direct path in 1 step
Purpose: Test different path lengths in same run
```

### test8: Large Direct Path
```
Input: 10 boxes with direct path from 1 to 10
Purpose: Test performance with larger graphs
```

### test9: Comprehensive Scenarios
```
Input: 3 test cases covering:
- Simple direct path
- Impossible scenario
- Multi-hop path
Purpose: Test all major scenario types together
```

### test10-test12: Additional Validation
```
Purpose: Additional test cases for path validation
Ensure robust handling of various graph structures
```

### test13: Multi-Hop Required
```
Input: 8 boxes requiring path 1→4→8
Purpose: Test BFS pathfinding with required intermediate steps
```

### test14: Large Graph Direct
```
Input: 9 boxes with direct connection to target
Purpose: Test direct path detection in larger graphs
```

### test15: Mixed Path Lengths
```
Input: 2 test cases with different complexities
- Test 1: 2-hop path (1→2→5)
- Test 2: Direct path (1→10)
Purpose: Test varied path lengths in single run
```

## Test Coverage

The test suite covers:

### Graph Structure Types:
- ✅ Direct connections (1→target)
- ✅ Chain connections (1→2→3→...→target)
- ✅ Branching graphs with multiple paths
- ✅ Disconnected graphs (impossible cases)
- ✅ Self-loops and complex connectivity

### Problem Sizes:
- ✅ Minimum size (N=2)
- ✅ Small graphs (N=3-5)
- ✅ Medium graphs (N=6-8)
- ✅ Larger graphs (N=9-10)

### Path Types:
- ✅ Length 1 (direct)
- ✅ Length 2 (one intermediate)
- ✅ Length 3+ (multiple intermediates)
- ✅ Impossible (no path)

### Edge Cases:
- ✅ Empty connection lists (0 outgoing edges)
- ✅ Self-referential connections
- ✅ Lexicographic ordering requirements
- ✅ Multiple test cases per input

### Algorithm Requirements:
- ✅ BFS shortest path finding
- ✅ Lexicographic path selection
- ✅ Path reconstruction
- ✅ Impossible case detection
- ✅ Proper output formatting