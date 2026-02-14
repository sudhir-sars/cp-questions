class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.length();
        int m = text2.length();

        vector<int> dp(m+1, 0);

        for(int i = 1; i <= n; i++) {

            int prevDiagonal = 0;   // stores dp[i-1][j-1]

            for(int j = 1; j <= m; j++) {

                int temp = dp[j];   // store old dp[i-1][j]

                if(text1[i-1] == text2[j-1])
                    dp[j] = 1 + prevDiagonal;
                else
                    dp[j] = max(dp[j], dp[j-1]);

                prevDiagonal = temp;
            }
        }

        return dp[m];
    }
};
