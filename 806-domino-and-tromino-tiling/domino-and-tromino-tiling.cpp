class Solution {
public:
int MOD=1e9+7;
    int numTilings(int n) {
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i<=n; i++){
            dp[i] = (dp[i-1]*2%MOD + dp[i-3])%MOD;
        }
        return dp[n]; 
    }
};