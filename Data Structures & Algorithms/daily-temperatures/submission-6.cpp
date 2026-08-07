class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> result(temp.size(), 0);
        stack<int> s;

        for (int i = 0; i < temp.size(); i++)
        {
            while (!s.empty() && temp[i] > temp[s.top()])
            {
                int previousDay = s.top();
                s.pop();

                result[previousDay] = i - previousDay;
            }

            s.push(i);
        }

        return result;
    }
};