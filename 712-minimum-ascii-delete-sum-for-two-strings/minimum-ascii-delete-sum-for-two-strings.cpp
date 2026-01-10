class Solution {
public:
    int n, m;

int solve(int i, int j, vector<vector<int>>& dp, string &s1, string &s2) {

    if (i == n && j == m) {
        return 0;
    }

    if (i == n) {
        int sum = 0;
        while (j < m) {
            sum += s2[j];
            j++;
        }
        return sum;
    }

    if (j == m) {
        int sum = 0;
        while (i < n) {
            sum += s1[i];
            i++;
        }
        return sum;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = INT_MAX;

    if (s1[i] == s2[j]) {
        ans = solve(i + 1, j + 1, dp, s1, s2);
    } else {
        ans = min(ans, s1[i] + solve(i + 1, j, dp, s1, s2));
        ans = min(ans, s2[j] + solve(i, j + 1, dp, s1, s2));
        ans = min(ans, s1[i] + s2[j] + solve(i + 1, j + 1, dp, s1, s2));
    }

    return dp[i][j] = ans;
}

int minimumDeleteSum(string s1, string s2) {
    n = s1.size();
    m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(0, 0, dp, s1, s2);
}

};