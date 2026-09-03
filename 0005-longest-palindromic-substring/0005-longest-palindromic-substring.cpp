class Solution {
public:
    string longestPalindrome(string s) {
         string ans = "";

       for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                int l = i, r = j;

                while (l < r && s[l] == s[r]) {
                    l++;
                    r--;
                }

                if (l >= r && j - i + 1 > ans.size())
                    ans = s.substr(i, j - i + 1);
            }
        }

        return ans;
    }
};