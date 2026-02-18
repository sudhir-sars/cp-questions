class Solution {
public:
    int dp[301][11];

    int compute(vector<int>& jobDifficulty, int index, int d, int n){
        if(d == 0 && index == n) return 0;
        if(d == 0 || index == n) return INT_MAX;

        if(dp[index][d] != -1) return dp[index][d];

        int ans = INT_MAX;
        int maxValue = INT_MIN;

        for(int k = index; k <= n - d; k++){
            maxValue = max(maxValue, jobDifficulty[k]);

            int next = compute(jobDifficulty, k+1, d-1, n);
            if(next != INT_MAX){
                ans = min(ans, maxValue + next);
            }
        }

        return dp[index][d] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n) return -1;

        memset(dp, -1, sizeof(dp));

        return compute(jobDifficulty, 0, d, n);
    }
};
