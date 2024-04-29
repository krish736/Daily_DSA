// 29-04-2024
// GFG
// Given a sorted array arr containing n elements with possibly some duplicate, the task is to find the first and last occurrences of an element x in the given array.
// Note: If the number x is not found in the array then return both the indices as -1.

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int firstOcc(int arr[], int n, int x){
        int s = 0, e = n -1;
        int mid = s + (e-s)/2;
        int ans = -1;
        
        for(int i = 0; i < n; i++){
            if(arr[mid] == x){
                ans = mid;
                e = mid -1;
            }
            else if(arr[mid] > x){
                e = mid -1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    
    int lastOcc(int arr[], int n, int x){
        int s = 0, e = n -1;
        int mid = s + (e-s)/2;
        int ans = -1;
        
        for(int i = 0; i < n; i++){
            if(arr[mid] == x){
                ans = mid;
                s = mid +1;
            }
            else if(arr[mid] > x){
                e = mid -1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
         vector<int> result;
        result.push_back(firstOcc(arr,n,x));
        result.push_back(lastOcc(arr,n,x));
        
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends