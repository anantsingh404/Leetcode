class Solution {
public:
      static const int MOD = 1e9 + 7;
    vector<vector<int>> memo;

    int solve(int i, int j) {
        if (j == 0) return 1;
        if (i <= 0 || i < j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        long long ans = solve(i - 1, j) % MOD;
        for (int p = 0; p < i; p++) {
            ans = (ans + solve(p, j - 1)) % MOD;
        }

        return memo[i][j] = ans;
    }

    int numberOfSets(int n, int k) {
        memo.assign(n, vector<int>(k + 1, -1));
        return solve(n - 1, k);
    }
};