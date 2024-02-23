// Leetcode
// 22-02-2024
// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n+1,-1);

        for(int i =0;i<nums.size();i++){
            v[nums[i]] = nums[i];
        }

        for(int i =0;i<v.size();i++){
            if(v[i]==-1){
                return i;
            }
        }

        return 0;
    }
};