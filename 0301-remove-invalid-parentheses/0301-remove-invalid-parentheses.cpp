class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
           vector<string> ans;
        queue<string> q;
        unordered_set<string> vis;

        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string x = q.front();
            q.pop();

            int bal = 0;
            bool valid = true;

            for (char c : x) {
                if (c == '(') bal++;
                else if (c == ')' && --bal < 0) {
                    valid = false;
                    break;
                }
            }

            if (valid && bal == 0)
                ans.push_back(x);

            if (!ans.empty()) continue;

            for (int i = 0; i < x.size(); i++) {
                if (x[i] == '(' || x[i] == ')') {
                    string t = x.substr(0, i) + x.substr(i + 1);
                    if (vis.insert(t).second)
                        q.push(t);
                }
            }
        }

        return ans;
    }
};