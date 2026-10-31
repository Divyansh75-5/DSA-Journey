class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();
        const int mod = 1e9 + 7;

        vector<vector<long long>> r(m, vector<long long>(n, 0));
        vector<vector<long long>> d(m, vector<long long>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long ways = (i == 0 && j == 0) ? 1 : (r[i][j] + d[i][j]) % mod;

                if (grid[i][j] == 1) {
                    if (i + 1 < m)
                        d[i+1][j] = (d[i+1][j] + r[i][j]) % mod;

                    if (j + 1 < n)
                        r[i][j+1] = (r[i][j+1] + d[i][j]) % mod;
                }
                else {
                    if (j + 1 < n)
                        r[i][j+1] = (r[i][j+1] + ways) % mod;

                    if (i + 1 < m)
                        d[i+1][j] = (d[i+1][j] + ways) % mod;
                }
            }
        }

        return (r[m-1][n-1] + d[m-1][n-1]) % mod;
    }
};