class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        bool check = true;
        int r , c , ans = 0;

        for(int i = 0; i<8; i++){
            bool temp = false;
            for(int j = 0; j<8; j++){
                if(board[i][j] == 'R'){
                    r = i;
                    c = j;
                    temp = true;
                    break;
                }
            }
            if(temp)
            break;
        }

        for(int i = r; i>=0; i--){
            if(i-1 >=0 && board[i-1][c] == 'p'){
                ans++;
                break;
            }else if(i-1 >=0 && board[i-1][c] == 'B'){
               break;
            }
        }

        for(int i = r; i<8; i++){
            if(i+1 < 8 && board[i+1][c] == 'p'){
                ans++;
                break;
            }else if(i+1 <8 && board[i+1][c] == 'B'){
               break;
            }
        }

        for(int j = c; j>=0; j--){
            if(j-1 >=0 && board[r][j-1] == 'p'){
                ans++;
                break;
            }else if(j-1 >=0 && board[r][j-1] == 'B'){
               break;
            }
        }

        for(int j = c; j<8; j++){
            if(j+1 < 8 && board[r][j+1] == 'p'){
                ans++;
                break;
            }else if(j+1 < 8 && board[r][j+1] == 'B'){
               break;
            }
        }

        return ans;
    }
};