#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Remove extra trailing spaces from string s
        istringstream iss(s);

        // Store words in a vector
        vector<string> words;
        string word;

        // Splitting the string by spaces and pushing the words into a vector
        while (iss >> word) {
            words.push_back(word);
        }

        // Result string
        string result = "";

        // Iterate through the vector in reverse order
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i] + " ";
        }

        // Trim the extra space at the end
        if (!result.empty()) {
            result.pop_back();  // Remove trailing space
        }

        return result;
    }
};

