class Solution {
public:
    int n;
    const long long NEG = -1e15;

    long long solve(int idx, int k, int state,
                    vector<int>& prices,
                    vector<vector<vector<long long>>>& dp)
    {
        if (idx == n) {
            if (state == 0) return 0;
            return NEG;
        }

        if (k == 0) {
            if (state == 0) return 0;
            return NEG;
        }

        if (dp[idx][k][state] != NEG) {
            return dp[idx][k][state];
        }

        long long ans = NEG;

        if (state == 0) {
            long long buy = -prices[idx] + solve(idx + 1, k, 1, prices, dp);
            long long sellShort = prices[idx] + solve(idx + 1, k, 2, prices, dp);
            long long skip = solve(idx + 1, k, 0, prices, dp);
            ans = max(buy, max(sellShort, skip));
        }
        else if (state == 1) {
            long long sell = prices[idx] + solve(idx + 1, k - 1, 0, prices, dp);
            long long hold = solve(idx + 1, k, 1, prices, dp);
            ans = max(sell, hold);
        }
        else {
            long long buyBack = -prices[idx] + solve(idx + 1, k - 1, 0, prices, dp);
            long long hold = solve(idx + 1, k, 2, prices, dp);
            ans = max(buyBack, hold);
        }

        return dp[idx][k][state] = ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();

        vector<vector<vector<long long>>> dp(
            n,
            vector<vector<long long>>(k + 1, vector<long long>(3, NEG))
        );

        return solve(0, k, 0, prices, dp);
    }
};
