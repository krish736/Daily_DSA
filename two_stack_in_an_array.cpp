// 01-04-2024
// Gfg
// Your task is to implement  2 stacks in one array efficiently. You need to implement 4 methods.

// twoStacks : Initialize the data structures and variables to be used to implement  2 stacks in one array.
// push1 : pushes element into first stack.
// push2 : pushes element into second stack.
// pop1 : pops element from first stack and returns the popped element. If first stack is empty, it should return -1.
// pop2 : pops element from second stack and returns the popped element. If second stack is empty, it should return -1.

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks
{
    public:
    int *arr;
    int top1;
    int top2;
    int size;
    
    
    twoStacks()
    {
        size=1000;
        arr= new int[size];
        top1=-1;
        top2=size;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
         if(top2-top1==1){
            cout<<"oveflow";
        }
        else{
            top1++;
            arr[top1]=x;
        }
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
       if(top2-top1==1){
            cout<<"oveflow";
        }
        else{
            top2--;
            arr[top2]=x;
        }
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1==-1){
            return -1;
        }
        else{
            int ans1=arr[top1];
            top1--;
            return ans1;
        }
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if(top2==size){
            return -1;
        }
        else{
            int ans2=arr[top2];
            top2++;
            return ans2;
        }
    }
};



//{ Driver Code Starts.

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>>Q;
        while(Q--){
        int stack_no;
        cin>>stack_no;
        int QueryType=0;
        cin>>QueryType;
        
        if(QueryType==1)
        {
            int a;
            cin>>a;
            if(stack_no ==1)
            sq->push1(a);
            else if(stack_no==2)
            sq->push2(a);
        }else if(QueryType==2){
        	if(stack_no==1)
            cout<<sq->pop1()<<" ";
            else if(stack_no==2)
            cout<<sq->pop2()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends