class Solution {
public:
     vector<string> phone = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> ans;

    void solve(string digits, int i, string s) {
        if (i == digits.size()) {
            ans.push_back(s);
            return;
        }

        for (char c : phone[digits[i] - '0']) {
            solve(digits, i + 1, s + c);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        solve(digits, 0, "");

        return ans;
    }
};