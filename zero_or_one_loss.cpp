// Leetcode
// 15_jan_2024
// You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

// Return a list answer of size 2 where:

//     answer[0] is a list of all players that have not lost any matches.
//     answer[1] is a list of all players that have lost exactly one match.

// The values in the two lists should be returned in increasing order.

// Note:

//     You should only consider the players that have played at least one match.
//     The testcases will be generated such that no two matches will have the same outcome.

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    map<int, pair<int, int>> m;
        for(auto i : matches){
            m[i[0]].first++;
            m[i[1]].second++;
        }
        vector<vector<int>> ans(2);
        for(auto [i, v] : m){
            if(v.second == 0) ans[0].push_back(i);
            else if(v.second == 1) ans[1].push_back(i);
        }
        return ans;
    }
};