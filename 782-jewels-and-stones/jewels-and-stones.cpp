class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool>isJewels(128,false);
        int count = 0;

        for(char j : jewels){
            isJewels[j] = true;
        }

        for(char j : stones){
            if(isJewels[j]){
                count++;
            }
        }
        return count;
    }
};