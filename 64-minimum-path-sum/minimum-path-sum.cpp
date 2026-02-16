class Solution {
public:


    int minPathSum(vector<vector<int>>& grid) {
        int numRows=grid.size();
        int numCols=grid[0].size();
        vector<vector<int>> cache(numRows,vector<int>(numCols,0));

        cache[numRows-1][numCols-1]=grid[numRows-1][numCols-1];

        for(int row=numRows-2;row>=0;row--){
            cache[row][numCols-1]=grid[row][numCols-1]+ cache[row+1][numCols-1];
        }

        for(int col=numCols-2;col>=0;col--){
            cache[numRows-1][col]=grid[numRows-1][col]+cache[numRows-1][col+1];
        }


        for(int row=numRows-2;row>=0;row--){
            for(int col=numCols-2;col>=0;col--){
                cache[row][col]=grid[row][col]+min(cache[row+1][col],cache[row][col+1]);
            }
        }

         return cache[0][0];
    }
};