class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v_res;
        vector<int> backup = nums;
        int res = 1;
        for (int i = 0, j = 0; j < nums.size(); i++)
        {
            printf("============ \n");
            printf("j: %d, i: %d \n", j, i);
            printf("============ \n");
            nums.erase(nums.begin() + j);
            printf ("nums[%d]: %d \n", i, nums[i]);
            res *= nums[i];
            printf ("res: %d \n", res);
            if (i == nums.size() - 1)
            {
                j++;
                i = -1;
                nums = backup;

                v_res.push_back(res);
                res = 1;
                printf("============ \n");
            }
            nums = backup;
        }

        return v_res;
    }
};
