// Leetcode
// 14-feb-2024
// Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

// A string is palindromic if it reads the same forward and backward.

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto i:words){
            string s=i;   
            reverse(s.begin(),s.end()); 
            if(s==i){
                return s;
            }
        }
        return "";
    }
};