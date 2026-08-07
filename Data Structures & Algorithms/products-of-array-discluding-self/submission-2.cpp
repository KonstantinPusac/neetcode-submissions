class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v_res;
        vector<int> backup = nums;
        int res = 1;
        for (int i = 0, j = 0; j < nums.size(); i++)
        {
            nums.erase(nums.begin() + j);
            res *= nums[i];
            if (i == nums.size() - 1)
            {
                j++;
                i = -1;

                v_res.push_back(res);
                res = 1;
            }
            nums = backup;
        }

        return v_res;
    }
};
