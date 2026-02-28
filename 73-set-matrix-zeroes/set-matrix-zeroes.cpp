class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // Step 1: Check if first row has zero
        for (int j = 0; j < numCols; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Step 2: Check if first column has zero
        for (int i = 0; i < numRows; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Step 3: Use first row and column as markers
        for (int i = 1; i < numRows; i++) {
            for (int j = 1; j < numCols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 4: Zero cells based on markers
        for (int i = 1; i < numRows; i++) {
            for (int j = 1; j < numCols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: Zero first row if needed
        if (firstRowZero) {
            for (int j = 0; j < numCols; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 6: Zero first column if needed
        if (firstColZero) {
            for (int i = 0; i < numRows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};