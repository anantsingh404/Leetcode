class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
    vector<pair<long long,long long>> vals;
    int n = power.size();

    
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && power[j] == power[i]) j++;
        vals.push_back({power[i], 1LL * (j - i) * power[i]});
        i = j;
    }
    int m = vals.size();
    vector<long long> dp(m, 0);
    dp[0] = vals[0].second;
    long long ans = dp[0];

    for (int i = 1; i < m; i++) {
        dp[i] = dp[i - 1]; 
        long long take = vals[i].second;

        
        if (vals[i].first - vals[i - 1].first > 2) {
            take += dp[i - 1];
        } else if (i >= 2 && vals[i].first - vals[i - 2].first > 2) {
            take += dp[i - 2];
        } else if (i >= 3 && vals[i].first - vals[i - 3].first > 2) {
            take += dp[i - 3];
        }
      
        dp[i] = max(dp[i], take);
        ans = max(ans, dp[i]);
    }

    return ans; 
    }
};