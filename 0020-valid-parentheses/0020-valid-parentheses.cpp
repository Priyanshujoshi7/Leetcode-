class Solution
{
public:
    bool isValid(string s)
    {
        int l = s.length();
        stack<int> st;
        for (int i = 0; i < l; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.size() == 0)
                    return false;
                char top = st.top();
                char ch = s[i];

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }
        if (st.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};