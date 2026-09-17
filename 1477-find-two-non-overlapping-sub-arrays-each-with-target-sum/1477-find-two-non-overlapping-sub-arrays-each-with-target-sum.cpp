class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
          int n = arr.size(), ans = INT_MAX;
        vector<int> best(n, INT_MAX);

        int l = 0, sum = 0, prev = INT_MAX;

        for (int r = 0; r < n; r++) {
            sum += arr[r];

            while (sum > target)
                sum -= arr[l++];

            if (sum == target) {
                int len = r - l + 1;

                if (l > 0 && best[l - 1] != INT_MAX)
                    ans = min(ans, len + best[l - 1]);

                prev = min(prev, len);
            }

            best[r] = prev;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};