class Solution {
public:
long long solve(int i, int k, vector<int>& nums, vector<vector<long long>>& dp) {
    if (i == nums.size()) {
        return (k == 0) ? 0 : 1e10;
    }
    if (k == 0) return 1e10;

    if (dp[i][k] != -1) return dp[i][k];

    long long ans = 1e10;
    long long flag = 0;
    for (int j = i; j < nums.size(); j++) {
        flag ^= nums[j];
        long long next = solve(j + 1, k - 1, nums, dp);
        ans = min(ans, max(flag, next));
    }

    return dp[i][k] = ans;
}

int minXor(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<long long>> dp(n, vector<long long>(k + 1, -1));
    return (int)solve(0, k, nums, dp);
}
};