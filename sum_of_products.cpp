// 12-04-2024
// GFG
// Given an array arr[] of size n. Calculate the sum of Bitwise ANDs ie: calculate sum of arr[i] & arr[j] for all the pairs in the given array arr[] where i < j.

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    long long pairAndSum(int n, long long arr[])
    {
        // code here
        long long sum = 0;
        int count[32] = {0};

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 32; ++j)
            {
                if (arr[i] & (1 << j))
                    count[j]++;
            }
        }

        for (int i = 0; i < 32; ++i)
        {
            sum += (long long)count[i] * (count[i] - 1) / 2 * (1LL << i);
        }

        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends