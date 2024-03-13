// 13-03-2024
// Leetcode
// Given a positive integer n, find the pivot integer x such that:

//     The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.

// Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

class Solution {
public:
    int pivotInteger(int n) {
        int leftBound = 1, rightBound =  n;
        int fullSum = (n * (n + 1))/2;

        while(leftBound <= rightBound){
            int midNum = leftBound + (rightBound - leftBound) / 2;
            int firstHlfSum = (midNum * (midNum + 1))/2;
            int secondHlfSum = fullSum - firstHlfSum + midNum;

            if(firstHlfSum == secondHlfSum){
                return midNum;
            }else if(firstHlfSum < secondHlfSum){
                leftBound = midNum + 1;
            }else{
                rightBound = midNum - 1;
            }
        }
        
        return -1;
    }
};