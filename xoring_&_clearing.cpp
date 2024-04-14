// 14-04-2024
// GFG
// You are given an array arr[] of size n. You need to do the following:

//     You need to calculate the bitwise XOR of each element in the array with its corresponding index (indices start from 0).
//     After step1, print the array.
//     Now, set all the elements of arr[] to zero.
//     Now, print arr[].

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void printArr(int n, int arr[])
    {
        // Your code for printing array here
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void setToZero(int n, int arr[])
    {
        // Use memset to set arr to zero
        memset(arr, 0, sizeof(int) * n);
        // printArr(n,arr);
    }

    void xor1ToN(int n, int arr[])
    {
        // Xor arr[i]^i

        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] ^ i;
            // printArr(n, arr);
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        obj.xor1ToN(n, arr);
        obj.printArr(n, arr);
        obj.setToZero(n, arr);
        obj.printArr(n, arr);
    }
    return 0;
}

// } Driver Code Ends