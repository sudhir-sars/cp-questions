class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long max1 = LONG_MIN;
        long max2 = LONG_MIN;
        long max3 = LONG_MIN;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            if (!st.count(nums[i])) {
                if (nums[i] > max1) {
                    max3 = max2;
                    max2 = max1;
                    max1 = nums[i];
                } else if (nums[i] > max2) {
                    max3 = max2;
                    max2 = nums[i];
                } else if (nums[i] > max3) {
                    max3 = nums[i];
                }
                st.insert(nums[i]);
            }
        }
        if (max3 == LONG_MIN) {
            return max1;
        }
        return max3;
    }
};