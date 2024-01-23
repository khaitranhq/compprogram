package main

import (
	"fmt"
	"strconv"
)

func largestPalindromic(num string) string {
	var occurrences [][10]int
	var parities map[[10]bool]int

	answerLeft := -1
	answerRight := -1

	for i, char := range num {
		// get digit at position i
		digit, _ := strconv.Atoi(string(char))

		// calculate occurrences
		row := [10]int{0}
		for j := 0; i != 0 && j <= 9; j++ {
			row[j] = occurrences[i-1][j]
		}

		row[digit]++
		occurrences = append(occurrences, row)

		// calculate parity of occurrences from 1 to i
		parity := [10]bool{false}
		for j := 0; j <= 9; j++ {
			parity[j] = (occurrences[i][j] % 2) == 0
		}

		parityValue, exists := parities[parity]

		// Case 1: all occurrences parities of sub-number is even
		// target parity is the same as parity
		if exists {
			answerLeft = parityValue
			answerRight = i
		}

		// Case 2: one digit has odd occurrences and the rest is even
		for oddDigit := 0; oddDigit <= 9; oddDigit++ {

		}

		// Save parity
		if !exists {
			parities[parity] = i
		}
	}

	return num[answerLeft:answerRight]
}

func main() {
	num := "444947137"
	fmt.Print(largestPalindromic(num))
}
