struct Solution;

impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool {
        const MAX: usize = 2001;
        let mut occurrences = [0; MAX];

        for number in arr {
            occurrences[number as usize] += 1;
        }

        return true;
    }
}

fn main() {}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn unique_occurrences() {
        let arr: Vec<i32> = vec![1, 2, 2, 1, 1, 3, -9, -9, -9, -9];
        assert!(Solution::unique_occurrences(arr));
    }

    #[test]
    fn not_unique_occurrences() {
        let arr: Vec<i32> = vec![1, 2, -3];
        assert!(Solution::unique_occurrences(arr));
    }
}
