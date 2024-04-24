// 24-04-2024
// GFG
// Given two arrays a and b both of size n. Given q queries in an array query each having a positive integer x denoting an index of the array a. For each query, your task is to find all the elements less than or equal to a[x] in the array b.

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,int q) {
        // Your code goes here;
        vector<int> res;
        int maxi=INT_MIN; 
        
        for(int i=0;i<n;i++){
            maxi = max(maxi,a[i]);
        }
        
        for(int i=0;i<n;i++){
            maxi = max(maxi,b[i]);
        }
        
        int arr[maxi+1]={0};
       
        for(int i=0;i<n;i++){
            arr[b[i]]++;   
        }
        
        for(int i=1;i<=maxi;i++){
            arr[i]=arr[i] + arr[i-1]; 
        }
        
        for(int i=0;i<q;i++){
            int ans=arr[a[query[i]]];
            res.push_back(ans);
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends