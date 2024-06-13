struct Solution;

impl Solution {
    pub fn relative_sort_array(arr1: Vec<i32>, arr2: Vec<i32>) -> Vec<i32> {
        const MAX: usize = 1009;
        let mut numbers_occurrence: Vec<i32> = vec![0; MAX];
        for number in arr1 {
            numbers_occurrence[number as usize] += 1;
        }

        let mut result: Vec<i32> = Vec::new();
        for number in arr2 {
            while numbers_occurrence[number as usize] > 0 {
                result.push(number);
                numbers_occurrence[number as usize] -= 1;
            }
        }

        for (index, &number) in numbers_occurrence.iter().enumerate() {
            for _i in 1..number + 1 {
                result.push(index as i32);
            }
        }

        return result;
    }
}

fn main() {
    let arr1 = vec![2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19];
    let arr2 = vec![2, 1, 4, 3, 9, 6];

    let result = Solution::relative_sort_array(arr1, arr2);
    print!("{:?}", result);
}
