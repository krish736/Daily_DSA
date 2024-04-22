// 22-04-2024
// GFG
// Given a 2D binary matrix(1-based indexed) a of dimensions nxm , determine the row that contains the minimum number of 1's.
// Note: The matrix contains only 1's and 0's. Also, if two or more rows contain the minimum number of 1's, the answer is the lowest of those indices.

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minRow(int n, int m, vector<vector<int>> a)
    {
        // code here
        int ans = INT_MAX;
        int r = n;
        for (int i = n - 1; i >= 0; i--)
        {
            int currRow = 0;
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1)
                {
                    currRow++;
                }
            }
            if (ans >= currRow)
            {
                ans = currRow;
                r = i;
            }
        }
        return r + 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends