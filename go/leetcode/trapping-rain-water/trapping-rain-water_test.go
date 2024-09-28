package trappingrainwater

import "testing"

func TestTrap(t *testing.T) {
	tests := []struct {
		height   []int
		expected int
	}{
		{[]int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6},
		{[]int{4, 2, 0, 3, 2, 5}, 9},
		{[]int{1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6},
		{[]int{2, 0, 2}, 2},
		{[]int{3, 0, 0, 2, 0, 4}, 10},
	}

	for index, test := range tests {
		result := trap(test.height)
		if result != test.expected {
			t.Errorf(
				"Test %d: For height %v, expected %d but got %d",
				index,
				test.height,
				test.expected,
				result,
			)
		}
	}
}
