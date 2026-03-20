impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        if nums.is_empty() {
            return;
        }

        let mut s = 0;
        let mut m = 0;
        let mut e = nums.len() - 1;

        while m <= e {
            match nums[m] {
                0 => {
                    nums.swap(s, m);
                    s += 1;
                    m += 1;
                }
                1 => {
                    m += 1;
                }
                _ => {
                    nums.swap(m, e);
                    if e == 0 {
                        break;
                    }
                    e -= 1;
                }
            }
        }
    }
}