struct Solution;

impl Solution {
    pub fn min_increment_for_unique(nums: Vec<i32>) -> i32 {
        let mut mut_nums = nums;
        mut_nums.sort();

        let mut result: i32 = 0;
        let mut current_unique_num: i32 = 0;
        for i in 0..mut_nums.len() {
            if current_unique_num < mut_nums[i] {
                current_unique_num = mut_nums[i];
            }
            result += (mut_nums[i] - current_unique_num).abs();
            current_unique_num += 1;
        }
        return result;
    }
}

fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod test {
    use super::Solution;

    #[test]
    fn test_case_1() {
        let result: i32 = Solution::min_increment_for_unique(vec![1, 2, 2]);
        assert_eq!(result, 1);
    }

    #[test]
    fn test_case_2() {
        let result: i32 = Solution::min_increment_for_unique(vec![3, 2, 1, 2, 1, 7]);
        assert_eq!(result, 6);
    }
}
