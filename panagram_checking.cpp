// Gfg
// 21-feb-2024
// Given a string s check if it is "Panagram" or not. 

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        int n = s.length();
        if (n < 26) {
            return false;
        }
        
        bool alpha[26] = {false};

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch >= 'a' && ch <= 'z') {
                alpha[ch - 'a'] = true;
            } else if (ch >= 'A' && ch <= 'Z') {
                alpha[ch - 'A'] = true;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (alpha[i] == false) {
                return false;
            }
        }

        return true;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends