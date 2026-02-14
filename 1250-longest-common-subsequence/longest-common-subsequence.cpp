class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {

        int lenText1 = text1.length();
        int lenText2 = text2.length();

        vector<int> prev(lenText2+1,0);
        vector<int> curr(lenText2+1,0);

        for(int index1 = 1; index1 <= lenText1; ++index1) {
            for(int index2 = 1; index2 <= lenText2; ++index2) {

                if(text1[index1-1] == text2[index2-1]) {
                    curr[index2] =
                        1 + prev[index2-1];
                } 
                else {
                    curr[index2] =
                        max(prev[index2],
                            curr[index2-1]);
                }
            }
            prev=curr;
        }

        return curr[lenText2];
    }
};
