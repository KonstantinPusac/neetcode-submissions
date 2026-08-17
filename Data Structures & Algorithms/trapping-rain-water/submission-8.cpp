class Solution {
public:
    int trap(vector<int>& h) {
        int left = 0; int right = h.size()-1;
        // Finding begginign and end
        while (left+1 < h.size() && h[left+1] > h[left])
            left++;
        while (right-1 > 0 && h[right-1] > h[right])
            right--;

        // Finding highest point
        int highest = 0;
        for (int i = 0; i < h.size(); i++)
        {
            if (h[highest] < h[i])
                highest = i;
        }

        // Filling with water
        int water = 0; int start = left++; int end = right--;
        while (true)
        {
            if (start == highest && end == highest)
                return water;
            
            // Left side
            if (start != highest)
            {
                if (h[start] > h[left])
                    water += h[start] - h[left++];
                else 
                    start = left++;
            }

            // Right side
            if (end != highest)
            {
                if (h[end] > h[right])
                    water += h[end] - h[right--];
                else
                    end = right--;
            }
        }
    }
};
