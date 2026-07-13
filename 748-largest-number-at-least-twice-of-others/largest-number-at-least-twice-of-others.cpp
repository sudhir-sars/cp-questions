class Solution {
public:
    int dominantIndex(vector<int>& nums) {
       int largest=nums[0];
       int slargest=-1;
       int index=0;
       for(int i=1;i<nums.size();i++){
        if(nums[i]>largest ){
            slargest=largest;
            largest=nums[i];
            index=i;
        }
        else if(nums[i]<largest && nums[i]>slargest){
            slargest=nums[i];
        }
       } 
       if(largest>=2*slargest) return index;
       else return -1;

    }
};