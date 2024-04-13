// 13-04-2024
// GFG
// Given a number x, reverse its binary form and return the answer in decimal.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long reversedBits(long long x)
    {
        // code here
        long long ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (x & 1 << i)
            {
                ans += pow(2, 31 - i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long X;

        cin >> X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends