class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        vector<int> ans(m);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> free_s;
        priority_queue<vector<long long>, vector<vector<long long>>, greater<>> busy_s;
        for(int i = 0; i < n; ++i) free_s.push({servers[i], i});
        long long t = 0;
        for(int j = 0; j < m; ++j) {
            t = max(t, (long long)j);
            if(free_s.empty()) t = max(t, busy_s.top()[0]);
            while(!busy_s.empty() && busy_s.top()[0] <= t) {
                free_s.push({busy_s.top()[1], busy_s.top()[2]});
                busy_s.pop();
            }
            auto s = free_s.top(); free_s.pop();
            ans[j] = s.second;
            busy_s.push({t + tasks[j], s.first, s.second});
        }
        return ans;
    }
};