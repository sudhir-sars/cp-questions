class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int mx=0;
        for(auto it:nums){
            mx=max(mx,it);
        }
        for(auto it:nums){
            ans+=mx-it;
        }
        return ans;
    }
};