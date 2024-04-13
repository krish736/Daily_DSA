// 13-04-2024
// Leetcode
// Given an array of positive integers nums and a positive integer target, return the minimal length of a
// subarray
// whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = INT_MAX;

        while (i < n)
        {
            sum += nums[i];
            while (sum >= target)
            {
                ans = min(ans, i - j + 1);
                sum -= nums[j];
                j++;
            }
            i++;
        }

        if (ans == INT_MAX)
        {
            return 0;
        }
        else
        {
            return ans;
        }
    }
};