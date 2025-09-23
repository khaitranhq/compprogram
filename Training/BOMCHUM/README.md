# BOMCHUM - Cluster Bombs Problem

## Problem Description

A war between two countries, **RU** and **UC**, is intensifying. RU uses cluster bombs with masses up to 10¹². The destructive power of each bomb is equal to the **sum of all its positive divisors**.

UC wants to defend itself by creating bombs with equivalent destructive power. As a programmer, your task is to calculate the destructive power for each of RU's bombs.

## Input Format

**File:** `BOMCHUM.INP`

- **Line 1:** A single positive integer `q` (q ≤ 10⁶) — the number of bombs
- **Line 2:** `q` positive integers `a₁, a₂, ..., aᵩ`, where each `aᵢ` is the mass of a bomb

## Output Format

**File:** `BOMCHUM.OUT`

- Output `q` numbers, where the i-th number is the sum of all positive divisors of `aᵢ`, separated by spaces

## Example

### Input (`BOMCHUM.INP`)

```
4
2 4 10 9
```

### Output (`BOMCHUM.OUT`)

```
3 7 18 13
```

### Explanation

- **2:** Divisors are {1, 2} → Sum = 3
- **4:** Divisors are {1, 2, 4} → Sum = 7
- **10:** Divisors are {1, 2, 5, 10} → Sum = 18
- **9:** Divisors are {1, 3, 9} → Sum = 13

## Constraints

- **Test Cases:** 25 total, each worth 0.2 points
- **Time Limit:** 1 second
- **Memory Limit:** 1024 MB

## Test Case Distribution

### Subtask 1 (40% of total score)

- `q ≤ 10⁴`
- `aᵢ ≤ 10³` for all `1 ≤ i ≤ q`

### Subtask 2 (40% of total score)

- `10⁴ < q ≤ 10⁵`
- `aᵢ ≤ 10⁶` for all `1 ≤ i ≤ q`

### Subtask 3 (20% of total score)

- `q ≤ 10⁶`
- `aᵢ ≤ 10¹²` for all `1 ≤ i ≤ q`
- `aᵢ₊₁ = aᵢ + 1` for all `1 ≤ i < q` (consecutive integers)

