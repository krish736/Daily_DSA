// 28-04-2024
// GFG
// Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value. If such a subarray do not exist return 0 in that case.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int i=0,j=0,current_sum=0,minLen=INT_MAX;
        while(j<n){
            current_sum+=arr[j];
            
            while(current_sum>x){
                minLen=min(minLen,j-i+1);
                current_sum-=arr[i];
                i++;
            }
            j++;
        }
        if(minLen!=INT_MAX)
            return minLen;
        else
            return 0;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends