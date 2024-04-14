// 14-04-2024
// Leetcode
// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> nums;
        stack<char> ops;
        int num = 0;
        int result = 0;
        int sign = 1;

        for (char c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else if (c == '+' || c == '-')
            {
                result += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            }
            else if (c == '(')
            {
                nums.push(result);
                ops.push(sign);
                result = 0;
                sign = 1;
            }
            else if (c == ')')
            {
                result += sign * num;
                result *= ops.top();
                ops.pop();
                result += nums.top();
                nums.pop();
                num = 0;
            }
        }

        result += sign * num;

        return result;
    }
};