// Gfg
// 25-02-2024
// Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	// Your code here
    	vector<int> v(n+1);
    	v[0]=1;
        v[1]=0;
        v[2]=0;
        
        for(int i =3;i<=n;i++){
            v[i]+=v[i-3];
        }
        for(int i =5;i<=n;i++){
            v[i]+=v[i-5];
        }
        for(int i =10;i<=n;i++){
            v[i]+=v[i-10];
        }
        return v[n];
    	
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends