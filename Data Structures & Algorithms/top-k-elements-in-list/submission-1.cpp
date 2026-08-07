class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int, int> brojac_el;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            brojac_el[nums[i]] = 0;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            brojac_el[nums[i]] += 1;
        }

        vector<pair<int, int>> sortirano;
        for(const auto& br_el : brojac_el)
        {
            sortirano.push_back({br_el.second, br_el.first});
        }
        sort(sortirano.rbegin(), sortirano.rend());

        for (int i = 0; i < k; i++)
        {
            res.push_back(sortirano[i].second);
        }

        return res;
    } 
};
