class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int num : nums) 
        {
            cout << num << " ";
        }
        cout << endl;
        int tmp = 1;
        int res;
        if (nums.size() > 0)
            res = 1;
        else 
            res = 0;

        for (int i = 0; i + 1 < nums.size(); i++)
        {
            if (nums[i] + 1 == nums[i+1] || nums[i] == nums[i+1])
            {
                if (nums[i] != nums[i+1])
                    tmp++;

                if (tmp > res)
                    res = tmp;
            }
            else 
            {
                tmp = 1;
            }
        }

        return res;
    }
};
