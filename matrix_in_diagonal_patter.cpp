// 12-02-2024
// Gfg
// Given a square matrix mat[][] of n*n size, the task is to determine the diagonal pattern which is a linear arrangement of the elements of the matrix as depicted in the following example:
// Input:
// n = 3
// mat[][] = {{1, 2, 3},
//            {4, 5, 6},
//            {7, 8, 9}}
// Output: {1, 2, 4, 7, 5, 3, 6, 8, 9}

//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         int n = mat.size();
        vector<int> adj[n+n-1];
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                adj[i + j].push_back(mat[i][j]);
            }
        }
        
        vector<int> res;
        for(int i=0; i<n+n-1; i++) {
            if(i % 2 == 0)
                reverse(adj[i].begin(), adj[i].end());
            for(auto x: adj[i])
                res.push_back(x);
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends