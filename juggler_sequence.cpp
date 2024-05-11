// 11-05-2024
// Gfg
// Juggler Sequence is a series of integers in which the first term starts with a positive integer number a and the remaining terms are generated from the immediate previous term using the below recurrence relation:

// Juggler Formula
// c:\Users\krish\AppData\Local\Temp\2220ffd2-353d-4b30-b2aa-68fe4047f959_1685087657.png
// Given a number n, find the Juggler Sequence for this number as the first term of the sequence until it becomes 1.

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> jugglerSequence(int n) {
        // code here
        vector<int> ans = {n};
        int prev = ans.back();
        
        while(prev != 1) {
            int temp;
            
            if(prev&1) {
                temp = pow(prev, 1.5);
            }
            else {
                temp = pow(prev, 0.5);
            }
            
            prev = temp;
            ans.push_back(temp);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends