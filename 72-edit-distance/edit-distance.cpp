class Solution {
public:
    int computeMinDistance(string& word1,string& word2,int index1, int index2, vector<vector<int>>& cache){
        if(index1<0){
            return index2+1;
        }
        if(index2<0){
            return index1+1;
        }
        if(cache[index1][index2]!=-1){
            return cache[index1][index2];
        }

        if(word1[index1]==word2[index2]){
            return cache[index1][index2]= computeMinDistance(word1,word2,index1-1,index2-1,cache);
        }else{
            return cache[index1][index2]= 1+ min({computeMinDistance(word1,word2,index1,index2-1,cache),
             computeMinDistance(word1,word2,index1-1,index2,cache)
            , computeMinDistance(word1,word2,index1-1,index2-1,cache)});
        }
    }
    int minDistance(string word1, string word2) {
        int lenWord1=word1.length();
        int lenWord2=word2.length();

        vector<vector<int>> cache(lenWord1,vector<int>(lenWord2,-1));
        
        return computeMinDistance(word1,word2,lenWord1-1,lenWord2-1,cache);
        
    }
};