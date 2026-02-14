class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {

        int lenText1 = text1.length();
        int lenText2 = text2.length();

        vector<vector<int>> lcsCache(lenText1+1,
                                     vector<int>(lenText2+1, 0));

        for(int index1 = 1; index1 <= lenText1; ++index1) {
            for(int index2 = 1; index2 <= lenText2; ++index2) {

                if(text1[index1-1] == text2[index2-1]) {
                    lcsCache[index1][index2] =
                        1 + lcsCache[index1-1][index2-1];
                } 
                else {
                    lcsCache[index1][index2] =
                        max(lcsCache[index1-1][index2],
                            lcsCache[index1][index2-1]);
                }
            }
        }

        return lcsCache[lenText1][lenText2];
    }
};
