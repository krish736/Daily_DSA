// 08-04-2024
// Gfg
// Given an array A of N integers. Your task is to write a program to find the maximum value of ∑arr[i]*i, where i = 0, 1, 2,., n 1.
// You are allowed to rearrange the elements of the array.
// Note: Since output could be large, hence module 109+7 and then print answer.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    const int mod=1e9+7;
    int Maximize(int a[],int n)
    {
        sort(a,a+n);
        unsigned long long ans = 0;
        for(unsigned long long i=0;i<n;i++){
            ans += a[i]*i;
        }
        ans = ans % 1000000007;
        return ans;
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends