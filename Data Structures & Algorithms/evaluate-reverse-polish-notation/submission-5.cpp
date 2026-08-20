class Solution {
public:
    bool isnumber(string s)
    {
        for (unsigned char c : s)
            if (!isdigit(c))
                if(c == '-' && s.size() > 1)
                    continue;
                else
                    return false;
        return true;
    }

    int calculate(int a, int b, char c)
    {
        switch (c)
        {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
    }

    int evalRPN(vector<string>& t) {
        vector<int> res = {};
        for (int i = 0; i < t.size(); i++)
        {
            if (isnumber(t[i]))
            {
                int num = stoi(t[i]);
                res.push_back(num);
            }
            else
            {
                int a = res[res.size() - 1]; res.pop_back();
                int b = res[res.size() - 1]; res.pop_back();
                res.push_back(calculate(b, a, t[i][0]));
            }
        }
        int result = res[0]; 
        return result;
    }
};
