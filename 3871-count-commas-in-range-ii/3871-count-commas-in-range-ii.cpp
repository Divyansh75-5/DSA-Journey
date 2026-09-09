class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        for (long long x = 1000; x <= n; x *= 1000) {
            ans += n - x + 1;
            if (x > n / 1000) break;
        }

        return ans;
    }
};