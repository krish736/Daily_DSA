// Leetcode
// 16-jan-2024
// Given two integers m and n, try making a special sequence of numbers seq of length n such that

//     seqi+1 >= 2*seqi 
//     seqi > 0
//     seqi <= m

// Your task is to determine total number of such special sequences possible.

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int numberSequence(int m, int n){
        // code here
        if(m < 0) {
            return 0;
        }
        
        if(n == 1) {
            return m;
        }

        
        return numberSequence(m/2, n-1) + numberSequence(m-1, n);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends