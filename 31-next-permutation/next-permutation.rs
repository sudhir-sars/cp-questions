impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
        
        let n=nums.len();

        for i in 0..n{
            let idx=n-i-1;
            if idx>0 && nums[idx]>nums[idx-1]{
                
                let mut smallest_from_right=n-1;
                while(nums[smallest_from_right]<=nums[idx-1]){
                    smallest_from_right-=1;
                }
                nums.swap(idx-1,smallest_from_right);
                nums[idx..n].reverse();
                return;
            }

        }
        nums.reverse();

    }
}