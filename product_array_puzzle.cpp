// 09-04-2024
// Gfg
// Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here 
        long long int product = 1;
        int zeroCount = 0;
        vector<long long int> result(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                product *= nums[i];
            } else {
                zeroCount++;
            }
        }
        
        if (zeroCount > 1) {
            return result;
        } else if (zeroCount == 1) {
            for (int i = 0; i < n; ++i) {
                if (nums[i] == 0) {
                    result[i] = product;
                    break;
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                result[i] = product / nums[i];
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends