package firstmissingpositive

import "testing"

func TestFirstMissingPositive(t *testing.T) {
    tests := []struct {
        nums     []int
        expected int
    }{
        {[]int{1, 2, 0}, 3},
        {[]int{3, 4, -1, 1}, 2},
        {[]int{7, 8, 9, 11, 12}, 1},
        {[]int{1, 2, 3, 4, 5}, 6},
    }

    for _, test := range tests {
        result := firstMissingPositive(test.nums)
        if result != test.expected {
            t.Errorf("For input %v, expected %d, but got %d", test.nums, test.expected, result)
        }
    }
}
