// GFG
// 08-jan-2024
// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> ans;
        unordered_map<int,int> m;
        
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        
        for(auto it:m){
            if(it.second == 2){
                ans.push_back(it.first);
            }
        }
        
        for(int i=0; i<n; i++){
            if(m.find(i+1) == m.end()){
                ans.push_back(i+1);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends