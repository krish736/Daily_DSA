// Gfg
// 17-jan-2024
// Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero. 

// Note: Return 1, if there is at least one triplet following the condition else return 0.

//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr, arr + n);

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            int target = -arr[i];

            while (left < right) {
                int currentSum = arr[left] + arr[right];

                if (currentSum == target) {
                    return 1;
                } else if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return 0;
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
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends