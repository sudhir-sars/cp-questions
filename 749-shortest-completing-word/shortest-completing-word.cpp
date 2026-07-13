class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string str = "";
        string ans;
        int length = INT_MAX;
        for(char c : licensePlate){
            if(isalpha(c)){
                str += tolower(c);
            }
        }
        licensePlate = str;
        unordered_map<char, int> mpp;
        unordered_map<char, int> mpp2;
        for(int i=0; i<licensePlate.size(); i++){
            mpp[licensePlate[i]]++;
        }
        for(int i=0; i<words.size(); i++){
            string word = words[i];
            mpp2 = mpp;
            for(int i=0; i<word.size(); i++){
                if(mpp2.find(word[i]) != mpp2.end()){
                    mpp2[word[i]]--;
                    if(mpp2[word[i]] == 0){
                        mpp2.erase(word[i]);
                    }
                    if(mpp2.size() == 0){
                        int wordLength = word.size();
                        if(wordLength < length){
                            ans = word;
                            length = wordLength;
                            break;
                        }
                    }

                }
            }
        }
        return ans;
    }
};