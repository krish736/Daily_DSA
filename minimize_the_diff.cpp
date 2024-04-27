// 27-04-2024
// GFG
// You are given an array arr of size n. You have to remove a subarray of size k , such that the difference between the maximum and minimum values of the remaining array is minimized.
// Find the minimum value obtained after performing the operation of the removal of the subarray and return it.

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        vector<int> leftmax(n), rightmax(n), leftmin(n), rightmin(n);
        
        leftmax[0] = leftmin[0] = arr[0];
        rightmax[n-1] = rightmin[n-1] = arr[n-1];
        
        
        for(int i=1; i<n; i++){
            int j = n-i-1;
            
            
            leftmin[i] = min(leftmin[i-1], arr[i]);
            leftmax[i] = max(leftmax[i-1], arr[i]);
            
            rightmax[j] = max(rightmax[j+1], arr[j]);
            rightmin[j] = min(rightmin[j + 1], arr[j]);
            
        }
        
        
        
        int ans = 1e9;
        
        for(int i=0; i<=n-k; i++){
            int x, y;
            if(i == 0){
                x = rightmin[i + k];
                y = rightmax[i + k];
            }else if(i + k == n){
                x = leftmin[i-1];
                y = leftmax[i-1];
            }else{
                x = min(leftmin[i-1], rightmin[i + k]);
                y = max(rightmax[i + k], leftmax[i -1]);
            }
            
            ans = min(ans, y-x);
            
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends