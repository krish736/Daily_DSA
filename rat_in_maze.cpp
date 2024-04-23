// 23-04-2024
// GFG
// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool check(vector<vector<int>> &m, int n, int newx, int newy, vector<vector<bool>> &vis)
    {

        if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && vis[newx][newy] != 1 && m[newx][newy] == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    vector<string> ans;

    void func(int x, int y, vector<vector<int>> &m, int n, vector<vector<bool>> &vis, string path)
    {

        // base case

        if (x == (n - 1) && y == (n - 1))
        {
            ans.push_back(path);
            return;
        }

        // u,d,r,l  => lexographically order ==> d,l,r,u

        // down
        if (check(m, n, x + 1, y, vis))
        {

            vis[x][y] = 1;

            func(x + 1, y, m, n, vis, path + 'D');

            vis[x][y] = 0;
        }

        // left
        if (check(m, n, x, y - 1, vis))
        {

            vis[x][y] = 1;

            func(x, y - 1, m, n, vis, path + 'L');

            vis[x][y] = 0;
        }

        // right
        if (check(m, n, x, y + 1, vis))
        {

            vis[x][y] = 1;

            func(x, y + 1, m, n, vis, path + 'R');

            vis[x][y] = 0;
        }

        // up
        if (check(m, n, x - 1, y, vis))
        {

            vis[x][y] = 1;

            func(x - 1, y, m, n, vis, path + 'U');

            vis[x][y] = 0;
        }

        return;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        string path = "";

        if (m[0][0] == 0)
        {
            return ans;
        }

        func(0, 0, m, n, vis, path);
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
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends