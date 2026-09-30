class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        function<void(int,int)> f = [&](int i, int t) {
            if (t == 0) {
                ans.push_back(temp);
                return;
            }
            if (i >= candidates.size() || t < 0)
                return;
            temp.push_back(candidates[i]);
            f(i, t - candidates[i]);
            temp.pop_back();

            f(i + 1, t);
        };
        f(0, target);
        return ans;
    }
};