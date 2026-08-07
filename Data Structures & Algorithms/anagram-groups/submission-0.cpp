class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> res_element;
        vector<string> old_order = strs;

        for(int i = 0; i < strs.size(); i++)
        {
            sort(strs[i].begin(), strs[i].end());
        }

        for (int i = 0; i < strs.size();)
        {
            res_element.clear();
            res_element.push_back(old_order[i]);
            for (int j = i+1; j < strs.size();)
            {
                if (strs[i] == strs[j])
                {
                    res_element.push_back(old_order[j]);
                    strs.erase(strs.begin() + j);
                    old_order.erase(old_order.begin() + j);
                }
                else
                    j++;
            }
            strs.erase(strs.begin() + i);
            old_order.erase(old_order.begin() + i);
            res.push_back(res_element);
        }
        return res;
    }
};
