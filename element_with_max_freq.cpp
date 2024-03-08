// Leetcode
// 08-03-2024
// You are given an array nums consisting of positive integers.

// Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

// The frequency of an element is the number of occurrences of that element in the array.

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        int ans = 0;
        int mx = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            mx = max(mx, mp[nums[i]]);
        }

        for(auto m:mp){
            if(m.second == mx){
                ans += m.second;
            }
        }

        return ans;
    }
};