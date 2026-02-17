class Solution {
public:

    bool checkWordBreak(string &s, int index,
                        vector<string>& wordDict,
                        vector<int>& dp) {

        if(index == s.length()) {
            return true;
        }

        if(dp[index] != -1) {
            return dp[index];
        }

        for(string &word : wordDict) {

            int len = word.length();

            if(index + len <= s.length() &&
               s.compare(index, len, word) == 0) {

                if(checkWordBreak(s, index + len, wordDict, dp)) {
                    return dp[index] = true;
                }
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(), -1);  // -1 = uncomputed
        return checkWordBreak(s, 0, wordDict, dp);
    }
};
