// 17-04-2024
// Leetcode
// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

//     countAndSay(1) = "1"
//     countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.

// To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

class Solution
{
public:
    string countAndSay(int n)
    {
        string ans = "1";
        for (int i = 2; i <= n; i++)
        {
            string temp = "";
            int j = 0;
            while (j < ans.size())
            {
                int count = 0;
                char ch = ans[j];
                while (j <= ans.size() && ans[j] == ch)
                {
                    count++;
                    j++;
                }
                temp += to_string(count) + ch;
            }
            ans = temp;
        }

        return ans;
    }
};