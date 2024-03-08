// Gfg
// 08-03-2024
// Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string. Return true if it is possible to do else return false.

// Note: The driver code print 1 if the value returned is true, otherwise 0.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	     unordered_map<char,int> mp;
        for(auto it: s) mp[it]++; 
        
        for(char ch = 'a'; ch<='z'; ch++){
            unordered_map<char,int> mp1;
            mp[ch]--;
            
            for(auto it: mp){
                if(it.second > 0){
                    mp1[it.second]++;  
                } 
                if(mp1.size() > 1){
                    break;
                } 
            }
            
            if(mp1.size() == 1){
              return true;  
            }
            
            mp[ch]++;
        }
        
        return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends