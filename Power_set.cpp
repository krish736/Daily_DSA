// 20-04-2024
// Leetcode
// Given an integer array nums of unique elements, return all possible
// subsets
// (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution
{
private:
    void solve(int n, vector<int> nums, vector<int> op, int index, vector<vector<int>> &ans)
    {
        if (index == n)
        {
            ans.push_back(op);
            return;
        }

        solve(n, nums, op, index + 1, ans);

        int temp = nums[index];

        op.push_back(temp);

        solve(n, nums, op, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> op;
        int index = 0;

        solve(n, nums, op, index, ans);
        return ans;
    }
};