// GFG
// 20-jan-2024
// Given an array of integers. Find the Inversion Count in the array. 

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], long long n, long long l, long long h, long long mid, long long int &count) {
        long long i = l;
        long long j = mid+1;
        vector<long long>v;
        
        while(i <= mid && j <= h) {
            if(arr[i]<=arr[j]) {
                v.push_back(arr[i]);
                i++;
            }
            else {
                count += mid-i+1;
                v.push_back(arr[j]);
                j++;
            }
        }
        
        while(i<=mid) {
            v.push_back(arr[i]);
            i++;
        }
        while(j<=h) {
            v.push_back(arr[j]);
            j++;
        }
        
        long long k = l;
        for(long long l = 0; l<v.size() ; l++) {
            arr[k++] = v[l];
        }
    }
    
    void merge_sort(long long arr[], long long n, long long l, long long h, long long int &count) {
        if(l<h) {
            int mid = (l+h)/2;
            merge_sort(arr,n,l,mid,count);
            merge_sort(arr,n,mid+1,h,count);
            merge(arr,n,l,h,mid,count);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int count = 0;
        
        merge_sort(arr,N,0,N-1,count);
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends