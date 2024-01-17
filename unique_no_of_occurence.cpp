// Leetcode
// 17-jan-2024
// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;

        for(auto it:arr){
            m[it]++;
        }

        unordered_set<int> s;

        for(auto it:m){
            if(s.count(it.second)){
                return false;
            }

            s.insert(it.second);
        }

        return true;
    }
};