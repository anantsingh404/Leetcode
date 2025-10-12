static constexpr int MOD = 1e9 + 7;
static int C[31][31], dp[31][31][50][31];

class Solution {
    int n;
    void buildC() {
        if (C[0][0]) return;
        for (int i = 0; i <= 30; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
    int solve(int rem, int need, int idx, int carry, vector<int>& a) {
        int bits = __builtin_popcount(carry);
        if (rem < 0 || need < 0 || rem + bits < need) return 0;
        if (rem == 0) return need == bits;
        if (idx >= n) return 0;
        int &res = dp[rem][need][idx][carry];
        if (res != -1) return res;
        long long ans = 0, pw = 1;
        for (int t = 0; t <= rem; t++) {
            long long ways = (1LL * C[rem][t] * pw) % MOD;
            int nc = carry + t;
            ans = (ans + ways * solve(rem - t, need - (nc & 1), idx + 1, nc >> 1, a)) % MOD;
            pw = (pw * a[idx]) % MOD;
        }
        return res = ans;
    }
public:
    int magicalSum(int m, int k, vector<int>& a) {
        buildC();
        n = a.size();
        memset(dp, -1, sizeof(dp));
        return solve(m, k, 0, 0, a);
    }
};
