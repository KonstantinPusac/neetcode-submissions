class Solution {
public:

    bool isOpen(char ch)
    {
        if (ch == '{' || ch == '[' || ch == '(')
            return true;
        return false;
    }
    bool isPair(char ch1, char ch2)
    {
        if (ch1 == '{' && ch2 == '}')
            return true;
        if (ch1 == '[' && ch2 == ']')
            return true;
        if (ch1 == '(' && ch2 == ')')
            return true;

        return false;
    }
    bool isValid(string s) {
        vector<char> el = {};
        for (int i = 0; i < s.length(); i++)
        {
            if (isOpen(s[i]))
            {
                el.push_back(s[i]);
            }
            else
            {
                if (i-1 < 0 || el.empty())
                    return false;
                if (isPair(el.back(), s[i]))
                    el.pop_back();
                else
                    return false;
            }
        }

        if (el.empty())
            return true;
        else
            return false;
    }
};
