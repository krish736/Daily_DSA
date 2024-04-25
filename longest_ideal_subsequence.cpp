// 25-04-2024
// Leetcode
// You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

//     t is a subsequence of the string s.
//     The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.

// Return the length of the longest ideal string.

// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

// Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.

class Solution {
public:
    int checkCnt(int idx, int k, vector<int>& cnts){
        int ans = 0;
        int cnt = 0;
        int currIdx = idx;

        while(currIdx>=0 && cnt<=k){
            ans = max(ans, cnts[currIdx]);
            currIdx--;
            cnt++;
        }

        currIdx = idx;
        cnt = 0;

        while(currIdx<26 && cnt<=k){
            ans = max(ans, cnts[currIdx]);
            currIdx++;
            cnt++;
        }
        return ans;
    }

    int longestIdealString(string s, int k) {
        vector<int> cnts(26,0);
        int ans;

        for(int i=0; i<s.size(); i++){
            int idx = s[i] - 'a';
            cnts[idx] = checkCnt(idx,k,cnts) + 1;
        }

        for(int i=0; i<cnts.size(); i++){
            ans = max(ans,cnts[i]);
        }

        return ans;
    }
};