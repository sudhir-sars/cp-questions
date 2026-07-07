class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int ans = 0;
        vector<int> vec = nums;
        int max_dig_ran = INT_MIN;

        for (auto &i : vec) {
            int sm = INT_MAX, lar = INT_MIN;

            while (i) {
                int x = i % 10;
                sm = min(sm, x);
                lar = max(lar, x);
                i /= 10;
            }

            max_dig_ran = max(max_dig_ran, lar - sm);
            i = lar - sm;
        }

        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == max_dig_ran) {
                ans += nums[i];
            }
        }

        return ans;
    }
};