// 25-03-2024
// Gfg
// Given a positive integer n. Your task is to generate a string list of all n-bit binary numbers where, for any prefix of the number, there are more or an equal number of 1's than 0's. The numbers should be sorted in decreasing order of magnitude.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	    vector<string>v;

        void solve(int c0,int c1,string s,int n){
            if(s.length()==n){
                if(c1>=c0)
                v.push_back(s);
                return;
            }
            
            if(c0<=c1){
                solve(c0+1,c1,s+"0",n);
                solve(c0,c1+1,s+"1",n);
            }
        }
        
        
        vector<string> NBitBinary(int n)
        {
            // Your code goes here
            solve(0,0,"",n);
            reverse(v.begin(),v.end());
            return v;
        }
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends