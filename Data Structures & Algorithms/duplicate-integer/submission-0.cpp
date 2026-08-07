class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<int> tmp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count(tmp.begin(), tmp.end(), nums[i]))
                return true;
            tmp.push_back(nums[i]);
        }

        return false;
    }
};