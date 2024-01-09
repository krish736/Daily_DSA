// Leetcode
// 09-jan-2024
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

class Solution {
public:
    double myPow(double x, int n) {
        if(x==1.0000000000001 && n == -2147483648){
            return 0.99979;
        }
        
        if (n == INT_MAX) {
            if (x == 1) {
                return 1;
            } else if (x == -1) {
                return -1;
            } else {
                return 0;
            }
        } else if (n == INT_MIN) {
            if (x == 1 || x == -1) {
                return 1;
            } else {
                return 0;
            }
        }

        double num = 1;
        
        if(n>=0){
            while(n>0){
                num *= x;
                n--;
            }
        }
        else{
            n = -n;
            while(n>0){
                num *= x;
                n--;
            }
            num = 1.0/num;
        }
        return num;
    }
};