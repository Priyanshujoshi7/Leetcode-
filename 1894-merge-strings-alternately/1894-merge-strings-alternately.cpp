class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result="";
        int i = 0;
        int a = word1.length();
        int b = word2.length();
        while(i<a||i<b){
            if(i<a){
                result +=word1[i];
            }
            if(i<b){
                result+=word2[i];
            }
            i++;
        }
        return result;
        
    }
};