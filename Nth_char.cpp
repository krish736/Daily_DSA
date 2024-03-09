// Gfg
// 09-03-2024
// Given a binary string s. Perform r iterations on string s, where in each iteration 0 becomes 01 and 1 becomes 10. Find the nth character (considering 0 based indexing) of the string after performing these r iterations (see examples for better understanding).

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        if (r == 0) return s[n];
    
        string ans;
        int len = min(n + 1, (int)s.length());
        
        for(int i = 0; i < r; i++) {
            ans = "";
            for(int j = 0; j < len; j++) {
                if(s[j] == '0') {
                    ans.append("01");
                } else {
                ans.append("10");
                }
            }
            s = ans;
        }
            
        return s[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends