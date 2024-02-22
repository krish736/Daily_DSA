// Leetcode
// 22-02-2024
// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

//     The town judge trusts nobody.
//     Everybody (except for the town judge) trusts the town judge.
//     There is exactly one person that satisfies properties 1 and 2.

// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusting(n+1,0);
        vector<int> trusted(n+1,0);
        int ans = -1;
        for(auto i : trust){
            trusting[i[0]]++;
            trusted[i[1]]++;
        }

        for(int i=1; i<=n; i++){
            if(trusting[i]==0 && trusted[i]==n-1){
                ans = i;
            }
        }

        return ans;
    }
};