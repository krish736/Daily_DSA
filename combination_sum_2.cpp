// 13-05-2024
// Gfg
// Given an array of integers arr, the length of the array n, and an integer k, find all the unique combinations in arr where the sum of the combination is equal to k. Each number can only be used once in a combination.
// Return the combinations in the lexicographically sorted order, where each combination is in non-decreasing order.

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<vector<int>> ans;
    
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(),arr.end());
        vector<int> temp;
        help(0,k,arr,n,temp);
        return ans;
    }
    
    void help(int idx, int sum, vector<int>& arr, int n, vector<int>& temp){
        
        if(sum == 0){
            ans.push_back(temp);
            return;
        }
        
        if(idx == n){
            return;
        }
        
        for(int i = idx; i<n; i++){
            if(i != idx && arr[i] == arr[i-1]){
                continue;
            }
            if(arr[i]<=sum){
                temp.push_back(arr[i]);
                
                help(i+1, sum-arr[i], arr, n, temp);
                temp.pop_back();
            }
        }
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends