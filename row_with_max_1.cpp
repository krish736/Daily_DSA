// 03-04-2024
// Gfg
// Given a boolean 2D array of n x m dimensions, consisting of only 1's and 0's, where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {

        if (n == 0) return -1; 

        int maxOnesRow = -1;
        int maxOnesCount = 0;
        int currentRow = 0;
        int currentCol = m - 1;

        while (currentRow < n && currentCol >= 0) {
            if (arr[currentRow][currentCol] == 1) {
                maxOnesRow = currentRow;
                maxOnesCount = m - currentCol;
                currentCol--;
            } else {
                currentRow++;
            }
        }

        return maxOnesRow;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends