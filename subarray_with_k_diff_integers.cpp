// 30-03-2024
// Leetcode
// Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A good array is an array where the number of different integers in that array is exactly k.

//     For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

// A subarray is a contiguous part of an array.

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int sub_with_max_element_k = subarray_with_atmost_k(nums,k);
        int reduced_sub_with_max_k = subarray_with_atmost_k(nums,k-1);
        return (sub_with_max_element_k - reduced_sub_with_max_k);
    }
    int subarray_with_atmost_k(vector<int>& nums,int k){
        unordered_map<int,int> map;
        int left = 0 , right = 0,ans = 0;
        while(right<nums.size()){
            map[nums[right]]++;
            while(map.size()>k){
                map[nums[left]]--;
                if(map[nums[left]]==0)map.erase(nums[left]);
                left++;
            }
            ans += right-left+1; // basically the size of subarray;
            right++;
        }
        return ans;
    }
};