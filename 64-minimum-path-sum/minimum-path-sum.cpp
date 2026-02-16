class Solution {
public:

    int computeMinPath(vector<vector<int>>& grid, int row, int col, int numRows, int numCols ,vector<vector<int>>& cache){
        if(row==numRows-1 && col==numCols-1){
            return grid[row][col];
        }

        if(row>=numRows ||col>=numCols){
            return INT_MAX;
        }

        if(cache[row][col]!=-1){
            return cache[row][col];
        }

        int right=computeMinPath(grid,row,col+1,numRows,numCols,cache);
        int down=computeMinPath(grid,row+1,col,numRows,numCols,cache);

        return cache[row][col]= grid[row][col]+ min(right,down);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int numRows=grid.size();
        int numCols=grid[0].size();
        vector<vector<int>> cache(numRows,vector<int>(numCols,-1));

         return computeMinPath(grid,0,0,numRows,numCols,cache);
        
    }
};