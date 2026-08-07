#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sorted copy of nums
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        // Factorial
        int fact_n = 1, fact_n_n1 = 1;
        for (int i = 1; i <= nums.size(); i++)
        {
            fact_n *= i;
        }
        
        for (int i = 1; i <= (nums.size() - 2); i++)
        {
            fact_n_n1 *= i;
        }
        cout << nums.size() << endl;

        // Number of all combinations
        int comb_num = fact_n/(2*fact_n_n1);

        // Finding all sums of 2 elements
        multimap<int, vector<int>, greater<int>> two_sum = {};
        int x,  y, counter = 0;
        for (int i = 0, j = 1; ; i++)
        {
            // Helper vars
            x = i;
            y = i + j;
            
            // Overlap
            while (y > nums.size() - 1)
            {
                y = y - nums.size();
            }
            while (x > nums.size() - 1)
            {
                x = x - nums.size();
            }

            // Sum logic
            vector<int> sum_arr = {sorted_nums[x], sorted_nums[y]};
            two_sum.insert({sorted_nums[x] + sorted_nums[y], sum_arr});

            // Checking the end of cycle
            if (counter == nums.size() - 1)
            {
                j++;
                counter = -1;
            }
            counter++;

            if (x == 0 && y == nums.size()-1)
                break;
        }

        // Finding three sum
        vector<vector<int>> result = {};
        for (const auto& [sum, values] : two_sum) 
        {
            vector<int> cleaned_nums = sorted_nums;

            if (auto it = ranges::find(cleaned_nums, values[0]); it != cleaned_nums.end()) 
            {
                cleaned_nums.erase(it);
            }
            
            if (auto it = ranges::find(cleaned_nums, values[1]); it != cleaned_nums.end()) 
            {
                cleaned_nums.erase(it);
            }
            
            if (ranges::contains(cleaned_nums, sum*(-1)))
            {
                vector<int> elem = {values[0], values[1], sum*(-1)};
                sort(elem.begin(), elem.end());
                result.push_back(elem);
            }
        }

        // Get rid of duplicates
        vector<vector<int>> res = {};
        for (int i = 0; i < result.size(); i++)
        {
            if (!ranges::contains(res, result[i]))
                res.push_back(result[i]);
        }

        return res;
    }
};
