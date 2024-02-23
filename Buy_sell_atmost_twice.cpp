// Gfg
// 23-02-2024
// In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, the second transaction can only start after the first one is complete (buy->sell->buy->sell). The stock prices throughout the day are represented in the form of an array of prices. 

// Given an array price of size n, find out the maximum profit that a share trader could have made.

//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            int n = price.size();
            if (n < 2) return 0;

            int maxProfit = 0;

            vector<int> forwardProfit(n, 0);
            int minPrice = price[0];
            
            for (int i = 1; i < n; ++i) {
                minPrice = min(minPrice, price[i]);
                forwardProfit[i] = max(forwardProfit[i - 1], price[i] - minPrice);
            }

            vector<int> backwardProfit(n, 0);
            int maxPrice = price[n - 1];
            
            for (int i = n - 2; i >= 0; --i) {
                maxPrice = max(maxPrice, price[i]);
                backwardProfit[i] = max(backwardProfit[i + 1], maxPrice - price[i]);
            }

            for (int i = 0; i < n; ++i) {
                maxProfit = max(maxProfit, forwardProfit[i] + backwardProfit[i]);
            }

            return maxProfit;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends