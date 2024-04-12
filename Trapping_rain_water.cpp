// 12-04-2024
// Leetcode
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

class Solution
{
public:
    int trap(std::vector<int> &height)
    {
        int i = 0;
        int left_max = height[0];
        int sum = 0;
        int j = height.size() - 1;
        int right_max = height[j];

        while (i < j)
        {
            if (left_max <= right_max)
            {
                sum += (left_max - height[i]);
                i++;
                left_max = std::max(left_max, height[i]);
            }
            else
            {
                sum += (right_max - height[j]);
                j--;
                right_max = std::max(right_max, height[j]);
            }
        }

        return sum;
    }
};