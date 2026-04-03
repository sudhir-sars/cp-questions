class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fact(10, 1);
        for(int i = 2; i<10; i++){
            fact[i] = fact[i-1]*i;
        }
        string s = to_string(n);
        int sum = 0;
        for(auto c : s){
            sum+=fact[c-'0'];
        }
        string ss = to_string(sum);
        sort(ss.begin(),ss.end());
        sort(s.begin(),s.end());
        if(s == ss) return true;
        return false;
    }
};