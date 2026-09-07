class Solution {
public:
    int distinctSubseqII(string s) {
         int MOD = 1000000007;
        vector<long long> dp(s.size() + 1);
        vector<long long> last(26);

        for (int i = 1; i <= s.size(); i++) {
            int x = s[i - 1] - 'a';

            dp[i] = (2 * dp[i - 1] + 1 - last[x] + MOD) % MOD;

            last[x] = dp[i - 1] + 1;
        }

        return dp[s.size()];
    }
};