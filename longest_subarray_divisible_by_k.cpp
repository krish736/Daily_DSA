GFG
11-jan-2024
Given an array arr containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int>yp;
	    int sum  = 0;
	    int ans = 0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        int rem = sum%k;
	        if(rem<0){
	            rem+=k;  
	        }
	        if(rem == 0){
	            ans = i+1;
	        }
	        else{
	            if(yp[rem]){
	                ans = max(ans,i+1 - yp[rem]);
	            }else{
	                yp[rem] = i+1;
	            }
	        }
	        
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends