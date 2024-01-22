// Gfg
// 22-jan-2024
// Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.

// Note: for the reference of this question take first fibonacci number to be 1.


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        int mod=1000000007;
        int c;
        if(n<2){
           return 1;
        }
        int a=0;
        int b=1;
        for(int i=1;i<n;i++){
           c=(a+b)%mod;
           a=b;
           b=c;
        }
        return c%mod;
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends