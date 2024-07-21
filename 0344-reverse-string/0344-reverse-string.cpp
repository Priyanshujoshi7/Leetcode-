class Solution {
public:
    void reverseString(vector<char>& s) {
    int st=0;
    int size= s.size();
    int e=size-1;
    while(st<=e){
        swap(s[st],s[e]);
        st++;
        e--;

    }
    }
};