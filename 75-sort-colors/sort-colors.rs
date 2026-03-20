impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
       

        let mut s = 0;
        let mut m = 0;
        let mut e = nums.len();

        while m < e {
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
                     e -= 1;
                    nums.swap(m, e);
                    
                   
                }
            }
        }
    }
}