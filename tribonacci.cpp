// 24-04-2024
// Leetcode
// The Tribonacci sequence Tn is defined as follows: 

// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

// Given n, return the value of Tn.

class Solution {
private:
    // int rec (int n){
    //     if(n==0){
    //         return 0;
    //     }
    //     if(n==1 || n==2){
    //         return 1;
    //     }

    //     return rec(n-3)+rec(n-2)+rec(n-1);
    // }

public:
    int tribonacci(int n) {
        // int ans = 0;
        // return rec(n);
        // return ans;

        int f[38];
        f[0] = 0;
        f[1] = 1;
        f[2] = 1;

        for(int i=3; i<=n; i++){
            f[i] = f[i-3] + f[i-2] + f[i-1];
        }

        return f[n];
    }
};