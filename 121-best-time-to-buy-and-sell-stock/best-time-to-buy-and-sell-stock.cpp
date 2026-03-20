class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int ans=0;
        int n=prices.size();
        int prevMin=prices[0];

        for(int price:prices){

            if(price<prevMin){
                prevMin=price;
            }
            
            ans=max(ans,price-prevMin);
        }

        return ans;
        
    }
};