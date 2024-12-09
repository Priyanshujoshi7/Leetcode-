class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
    string decode(const string& s, int& i) {
        string result = "";
        while (i < s.length() && s[i] != ']') {
            if (isdigit(s[i])) {
                int k = 0;
                while (i < s.length() && isdigit(s[i])) {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }
                i++; 
                string decoded = decode(s, i); 
                i++; 
                while (k-- > 0) {
                    result += decoded;
                }
            } else {
                result += s[i];
                i++;
            }
        }
        return result;
    }
};
