class Solution {
public:
    int numberOfSets(int n, int k) {
       long long ans = 1;
        int MOD = 1000000007;

        for(int i = 1; i <= 2 * k; i++) {
            ans = ans * (n + k - 1 - i + 1) % MOD;
            ans = ans * power(i, MOD - 2) % MOD;
        }

        return ans;
    }

    long long power(long long a, long long b) {
        long long ans = 1;
        while(b) {
            if(b & 1)
                ans = ans * a % 1000000007;
            a = a * a % 1000000007;
            b /= 2;
        }
        return ans;
    }
};