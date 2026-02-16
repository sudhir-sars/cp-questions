class Solution {
public:

    int computeChange(vector<int>& coins, int amount, int index,int numCoins,vector<vector<int>>& cache){
        if(index==numCoins-1){
            if(amount% coins[index]==0){
                return 1;
            }
            return 0;
        }

        if(cache[amount][index]!=-1){
            return cache[amount][index];
        }


        int notTake=computeChange(coins,amount, index+1,numCoins,cache);
        int take=0;
        if(amount>= coins[index]){
            take=computeChange(coins,amount-coins[index],index,numCoins,cache);
        }
        return  cache[amount][index]=notTake+take;
    }
    int change(int amount, vector<int>& coins) {

        int numCoins=coins.size();
        vector<vector<int>> cache(amount+1,vector<int>(numCoins,-1));

        return computeChange(coins,amount,0,numCoins,cache);
        
    }
};