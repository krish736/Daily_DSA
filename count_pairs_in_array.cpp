// 17-04-2024
// GFG
// Given an array arr of n integers, count all pairs (arr[i], arr[j]) in it such that i*arr[i] > j*arr[j] and 0 ≤ i < j < n.

// Note: 0-based Indexing is followed.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

class Solution
{
public:
    int countPairs(int arr[], int n)
    {
        // Your code goes here
        orderedMultiSet st;
        st.insert(arr[n - 1] * (n - 1));
        int ans = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            st.insert(arr[i] * i);
            ans += st.order_of_key(arr[i] * i);
        }

        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.countPairs(a, n) << endl;
    }
}
// } Driver Code Ends