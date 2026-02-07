pub struct Solution;

struct Stack<T> {
    elements: Vec<T>,
}

impl<T> Stack<T> {
    fn new() -> Self {
        Stack {
            elements: Vec::new(),
        }
    }

    fn push(&mut self, value: T) {
        self.elements.push(value);
    }

    fn pop(&mut self) {
        self.elements.pop();
    }

    fn top(&self) -> Option<&T> {
        self.elements.last()
    }

    fn is_empty(&self) -> bool {
        self.elements.is_empty()
    }
}

impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let mut stack: Stack<char> = Stack::new();

        let mut delete_count = 0;
        for c in s.chars() {
            if !stack.is_empty() && stack.top() == Some(&'b') && c == 'a' {
                stack.pop();
                delete_count += 1;
            } else {
                stack.push(c);
            }
        }

        return delete_count;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_minimum_deletions() {
        assert_eq!(Solution::minimum_deletions(String::from("aababbab")), 2);
        assert_eq!(Solution::minimum_deletions(String::from("bbaaaaabb")), 2);
    }
}
