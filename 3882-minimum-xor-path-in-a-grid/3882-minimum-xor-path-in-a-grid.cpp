class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
         int n = grid[0].size();
        vector<vector<bool>> dp(n, vector<bool>(1024));
        dp[0][grid[0][0]] = 1;

        for (auto& row : grid) {
            for (int j = 0; j < n; j++) {
                if (&row == &grid[0] && j == 0) continue;
                vector<bool> temp(1024);
                for (int x = 0; x < 1024; x++) {
                    if (j > 0 && dp[j - 1][x])
                        temp[x ^ row[j]] = 1;
                    if (dp[j][x])
                        temp[x ^ row[j]] = 1;
                }
                dp[j] = temp;
            }
        }
        for (int x = 0; x < 1024; x++)
            if (dp[n - 1][x]) return x;
        return 0;
    }
};