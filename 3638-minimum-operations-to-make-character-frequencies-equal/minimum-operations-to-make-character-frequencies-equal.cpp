class Solution {
public:
   vector<int> v;
    
    int findCost(int t) {
        vector<vector<int>> dp(26, vector<int>(2, -1));
        return dfs(t, dp, 0, 0);
    }

    int dfs(int t, vector<vector<int>>& dp, int i, bool canUsePrev){
        if (i == v.size()) return 0;
        if (dp[i][canUsePrev] == -1){
            int ans = dfs(t, dp, i + 1, 1) + v[i];
            if (v[i] < t && canUsePrev){
                int canTake = v[i - 1] > t ? v[i - 1] - t : v[i - 1];
                ans = min(ans, dfs(t, dp, i + 1, 0) + t - min(t, v[i] + canTake));
            }
            else{
                if (v[i] > t){
                    ans = min(ans, dfs(t, dp, i + 1, 1) + v[i] - t);
                }
                else{
                    ans = min(ans, dfs(t, dp, i + 1, 0) + t - v[i]);
                }
            }

            dp[i][canUsePrev] = ans;
        }
        return dp[i][canUsePrev];

    }

    int makeStringGood(string s) {
        v.resize(26);
        int l = 1, r = 0;
        for (auto& c : s)
            r = max(r, ++v[c - 'a']);
        int ans = INT_MAX;
        for (int i = 1; i <= r; ++i)
            ans = min(ans, findCost(i));
        return ans;
    }
};