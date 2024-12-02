class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream stream(sentence);
        string word;
        int index = 1; // To track the word number

        while (stream >> word) {
            if (word.find(searchWord) == 0) { 
                return index;
            }
            index++;
        }
        return -1; // No word matches the prefix
    }
};
