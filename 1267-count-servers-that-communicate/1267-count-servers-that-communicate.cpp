class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int r = 0, c = 0;

                    for(int k = 0; k < n; k++)
                        r += grid[i][k];

                    for(int k = 0; k < m; k++)
                        c += grid[k][j];

                    if(r > 1 || c > 1) ans++;
                }
            }
        }
        return ans;
    }
};