class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        long long tot=0;
        unordered_map<long long ,long long> mpp1,mpp2;
        //Calculating total sum:
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpp2[grid[i][j]]++;
                tot+=grid[i][j];
            }
        }
        long long left=0,right=0,down=0,up=0;
        //If n==1:
        if(n==1){
            for(int j=0;j<m-1;j++){
                left+=grid[0][j];
                long long right=tot-left;
                if(right==left) return true;
                long long diff;
                if(right>left){
                    diff=right-left;
                    if(grid[0][j+1]==diff||grid[0][m-1]==diff) return true;
                }
                else{
                    diff=left-right;
                    if(grid[0][0]==diff||grid[0][j]==diff) return true;
                }
            }
            return false;
        }

        //If m==1:
        if(m==1){
            for(int i=0;i<n-1;i++){
                up+=grid[i][0];
                long long down=tot-up;
                if(down==up) return true;
                long long diff;
                if(down>up){
                    diff=down-up;
                    if(grid[i+1][0]==diff||grid[n-1][0]==diff) return true;
                }
                else{
                    diff=up-down;
                    if(grid[i][0]==diff||grid[0][0]==diff) return true;
                }
            }
            return false;
        }

        //For row-wise cut:
        down=0;
        up=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                up+=grid[i][j];
                mpp1[grid[i][j]]++;
                mpp2[grid[i][j]]--;
                if(mpp2[grid[i][j]]==0) mpp2.erase(grid[i][j]);
            }
            down=tot-up;
            long long diff;
            if(down==up) return true;
            else if(down>up){
                diff=down-up;
                if(mpp2.find(diff)!=mpp2.end()){
                    if(i==n-2){
                        if(diff==grid[n-1][0]||diff==grid[n-1][m-1]) return true;
                        else continue;
                    } 
                    return true;
                }
            }
            else{
                diff=up-down;
                if(mpp1.find(diff)!=mpp1.end()){
                    if(i==0){
                        if(diff==grid[0][0]||diff==grid[0][m-1]) return true;
                        else continue;
                    }
                    return true;
                }
            }
        }

        //For column wise cut:
        left=0;
        right=0;
        mpp1.clear();
        mpp2.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpp2[grid[i][j]]++;
            }
        }
        for(int j=0;j<m-1;j++){
            for(int i=0;i<n;i++){
                left+=grid[i][j];
                mpp1[grid[i][j]]++;
                mpp2[grid[i][j]]--;
                if(mpp2[grid[i][j]]==0) mpp2.erase(grid[i][j]);
            }
            right=tot-left;
            long long diff;
            if(right==left) return true;
            else if(right>left){
                diff=right-left;
                if(mpp2.find(diff)!=mpp2.end()){
                    if(j==m-2){
                        if(diff==grid[0][m-1]||diff==grid[n-1][m-1]) return true;
                        else continue;
                    }
                    return true;
                }
            }
            else{
                diff=left-right;
                if(mpp1.find(diff)!=mpp1.end()){
                    if(j==0){
                        if(diff==grid[0][0]||diff==grid[n-1][0]) return true;
                        else continue;
                    }
                    return true;
                }
            }
        }
        return false;
    }
};