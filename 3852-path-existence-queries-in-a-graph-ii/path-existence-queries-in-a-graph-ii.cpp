class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>sorted(n);
        for(int i=0;i<n;i++) sorted[i]=pair<int,int>(nums[i],i);
        sort(sorted.begin(),sorted.end());
        vector<int>idx(n);
        for(int i=0;i<n;i++) idx[sorted[i].second]=i;
        int sze=(int)log2(n)+1;
        vector<vector<int>>up(n,vector<int>(sze));
        int r=0;
        for(int i=0;i<n;i++){
           if(r<i) r=i;
           while(r+1<n && sorted[r+1].first-sorted[i].first<=maxDiff) r++;
           up[i][0]=r;
        }
        for(int j=1;j<sze;j++){
            for(int node=0;node<n;node++){
                up[node][j]=up[up[node][j-1]][j-1];
            }
        }
        vector<int>ans;
        for(auto it:queries){
            int l=idx[it[0]],r=idx[it[1]];
            if(l>r) swap(l,r);
            if(l==r){
                ans.emplace_back(0);
                continue;
            }
            int steps=0;
            for(int j=sze-1;j>=0;j--){
                if(up[l][j]<r){
                    l=up[l][j];
                    steps+=(1<<j);
                }
            }
            if(up[l][0]>=r){
                steps++;
                ans.emplace_back(steps);
            }
            else ans.emplace_back(-1);
        }
        return ans;
    }
};