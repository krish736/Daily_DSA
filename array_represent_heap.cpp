// Gfg
// 22-02-2024
// Given an array arr of size n, the task is to check if the given array can be a level order representation of a Max Heap.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for(int i=0; i<n/2; i++){
            int root = arr[i];
            int left = arr[i*2 + 1];
            int right = arr[i*2 + 2];
            
            if(root<left || root<right){
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends