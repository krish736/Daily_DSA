// 28-04-2024
// Leetcode
// Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.

// Return true if these subarrays exist, and false otherwise.

// A subarray is a contiguous non-empty sequence of elements within an array.

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=1;i<nums.size();i++){
            int sum=nums[i-1]+nums[i];
            if(mp.find(sum)!=mp.end()){
                return true;
            }
            mp[sum]++;
        }   
        return false;
    }
};