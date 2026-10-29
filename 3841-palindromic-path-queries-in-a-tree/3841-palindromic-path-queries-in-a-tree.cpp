class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
          vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int L = 20, t = 0;
        vector<vector<int>> up(L, vector<int>(n));
        vector<int> in(n), out(n), dep(n), bit(n + 2);

        auto add = [&](int i, int x) {
            for (; i <= n; i += i & -i) bit[i] ^= x;
        };

        auto sum = [&](int i) {
            int x = 0;
            for (; i; i -= i & -i) x ^= bit[i];
            return x;
        };

        auto dfs = [&](auto&& self, int u, int p) -> void {
            in[u] = ++t;
            up[0][u] = p;
            for (int k = 1; k < L; k++)
                up[k][u] = up[k-1][up[k-1][u]];

            for (int v : g[u]) {
                if (v == p) continue;
                dep[v] = dep[u] + 1;
                self(self, v, u);
            }
            out[u] = t;
        };
        dfs(dfs, 0, 0);

        for (int i = 0; i < n; i++) {
            int x = 1 << (s[i] - 'a');
            add(in[i], x);
            add(out[i] + 1, x);
        }

        auto lca = [&](int u, int v) {
            if (dep[u] < dep[v]) swap(u, v);
            int d = dep[u] - dep[v];

            for (int k = 0; k < L; k++)
                if (d >> k & 1) u = up[k][u];

            if (u == v) return u;

            for (int k = L - 1; k >= 0; k--)
                if (up[k][u] != up[k][v])
                    u = up[k][u], v = up[k][v];

            return up[0][u];
        };

        vector<bool> ans;

        for (auto q : queries) {
            string op;
            int u, v;
            char c;
            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                ss >> c;
                int x = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                add(in[u], x);
                add(out[u] + 1, x);
                s[u] = c;
            } else {
                ss >> v;
                int w = lca(u, v);
                int x = sum(in[u]) ^ sum(in[v]) ^ (1 << (s[w] - 'a'));
                ans.push_back((x & (x - 1)) == 0);
            }
        }
        return ans;
    }
};