class Solution {
public:
const int mod = 1e9 + 7;
int n, m;
vector<vector<int>> dp;

int solve(int i, int j, string &target, vector<vector<int>> &mp) {
    if (j == 0) {
        return 1; // Target completely formed
    }
    if (i <= 0 || i < j) {
        return 0; // No more columns or insufficient characters
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    long long count = solve(i - 1, j, target, mp); // Skip current column

    if (i <= n) { // Bounds check for `mp[..][i]`
        long long fc = mp[target[j - 1] - 'a'][i - 1];
        if (fc > 0) {
            count = (count + fc * solve(i - 1, j - 1, target, mp) % mod) % mod;
        }
    }

    return dp[i][j] = count % mod;
}

int numWays(vector<string> &words, string target) {
    n = words[0].size();
    m = target.size();
    dp.assign(n + 1, vector<int>(m + 1, -1));
    vector<vector<int>> mp(26, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (const auto &w : words) {
            mp[w[i] - 'a'][i]++;
        }
    }

    return solve(n, m, target, mp);
}
};