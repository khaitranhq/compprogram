package firstmissingpositive

func firstMissingPositive(nums []int) int {
	n := len(nums)
	for i := 0; i < n; i++ {
		nums = append(nums, nums[i])
	}

	for i := n; i < 2*n; i++ {
		nums[i] = 0
	}

	for i := 0; i < n; i++ {
		if nums[i] > 0 && nums[i] <= n {
			nums[nums[i]-1+n] = 1
		}
	}

	for i := 0; i < n; i++ {
		if nums[i+n] == 0 {
			return i + 1
		}
	}
	return n + 1
}
