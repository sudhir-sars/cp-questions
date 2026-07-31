class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        vector<int> freq(26,0);
        for(auto ele: word) freq[ele-'a']++;
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0) pq.push(freq[i]);
        }
        int count=0,mulFact=0;
        while(!pq.empty()){
            if(count%8==0) mulFact++;

            int x=pq.top();pq.pop();count++;
            ans+=(mulFact*x);
        }
        return ans;
    }
};