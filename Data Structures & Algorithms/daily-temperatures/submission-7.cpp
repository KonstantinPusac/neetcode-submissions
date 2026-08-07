class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> result(temp.size(), 0);
        vector<int> st;
        st.reserve(temp.size());

        for (int i = 0; i < temp.size(); i++) {
            while (!st.empty() && temp[i] > temp[st.back()]) {
                int j = st.back();
                st.pop_back();
                result[j] = i - j;
            }

            st.push_back(i);
        }

        return result;
    }
};