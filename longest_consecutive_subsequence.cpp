// 03-04-2024
// GFg
// Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_set<int>s;
      int maxlen = 0 ;
      
      for(int i = 0 ; i < N ; i++){
          s.insert(arr[i]);
      }
      
      for(it : s){
          if(s.find(it-1) == s.end()){
              int count = 1;
              int val = it ;
              
              while(s.find(val+1) != s.end()){
                  count++;
                  val++;
              }
              
              maxlen = max(count , maxlen);
          }
      }
      
      return maxlen;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends