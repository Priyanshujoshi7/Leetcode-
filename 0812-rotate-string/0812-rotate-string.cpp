class Solution {
public:
    bool rotateString(string s, string goal) {
        // If lengths differ, `goal` cannot be a rotation of `s`
        if (s.size() != goal.size()) {
            return false;
        }

        // Concatenate `s` with itself
        string concatenated = s + s;

        // Check if `goal` is a substring of `concatenated`
        return concatenated.find(goal) != string::npos;
    }
};
