class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    long long maxSubarrayForK(const vector<int>& nums, int k) {
        long long best = LLONG_MIN;
        long long cur = LLONG_MIN;

        for (int x : nums) {
            long long val = (x % k == 0) ? x : -1LL * x;

            if (cur == LLONG_MIN)
                cur = val;
            else
                cur = max(val, cur + val);

            best = max(best, cur);
        }

        return best;
    }

    int divisibleGame(vector<int>& nums) {
        unordered_set<int> candidates;

        int mx = *max_element(nums.begin(), nums.end());

        // Collect all possible divisors (>1)
        for (int x : nums) {
            for (int d = 2; 1LL * d * d <= x; d++) {
                if (x % d == 0) {
                    candidates.insert(d);
                    candidates.insert(x / d);
                }
            }
            if (x > 1)
                candidates.insert(x);
        }

        // Represents every k > max(nums)
        candidates.insert(mx + 1);

        long long bestScore = LLONG_MIN;
        int bestK = INT_MAX;

        for (int k : candidates) {
            long long score = maxSubarrayForK(nums, k);

            if (score > bestScore || (score == bestScore && k < bestK)) {
                bestScore = score;
                bestK = k;
            }
        }

        long long ans = (bestScore % MOD) * bestK % MOD;
        ans = (ans + MOD) % MOD;

        return (int)ans;
    }
};