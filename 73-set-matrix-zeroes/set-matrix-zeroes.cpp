class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int numRows=matrix.size();
        int numCols=matrix[0].size();
        vector<int> zeroCols(numCols,0);
        vector<int> zeroRows(numRows,0);

        for(int i=0;i<numRows;i++){
            for(int j=0;j<numCols;j++){
                if(matrix[i][j]==0){
                    zeroRows[i]=1;
                    zeroCols[j]=1;

                }
            }
        }

        for(int i=0;i<numRows;i++){
            for(int j=0;j<numCols;j++){
                if(zeroRows[i] ||zeroCols[j]){
                  matrix[i][j]=0;

                }
            }
        }
        
    }
};