// 12-03-2024
// Leetcode
// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascalTraingle(rowIndex+1);

        for (int row=0; row<=rowIndex; row++)
        {
            pascalTraingle[row] = vector<int>(row+1);

            for (int col = 0; col<row+1; col++)
            {
                if (col == 0 || col == row)
                    pascalTraingle[row][col] = 1;
                else
                {
                    pascalTraingle[row][col] = pascalTraingle[row-1][col-1] + pascalTraingle[row-1][col];
                }
            }
        }

        return pascalTraingle[rowIndex];
    }
};