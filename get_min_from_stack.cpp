// 14-05-2024
// Gfg
// You are given N operations and your task is to Implement a Stack in which you can get a minimum element in O(1) time.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    stack<int> test;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
            if(test.size() == 0){
                return -1;
            }
            return test.top();
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(s.empty()){
               return -1;
           }
           
            int pop_ele;
            pop_ele = s.top();
            
            if(s.top() == test.top()){
                s.pop();
                test.pop();
            }else{
                s.pop();
            }
            
            return pop_ele;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
            if(s.size() == 0){
                s.push(x);
                test.push(x);
            }else if(x<=test.top()){
                s.push(x);
                test.push(x);
            }else{
                s.push(x);
            }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends