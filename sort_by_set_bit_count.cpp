// 30-04-2024
// GFG
// Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements. 

// Note: For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a stable sort.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    static bool comp(int a,int b){
       return __builtin_popcount(a)>__builtin_popcount(b);
   }
   void sortBySetBitCount(int arr[], int n)
   {
       // Your code goes here
       stable_sort(arr,arr+n,comp);
   }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends