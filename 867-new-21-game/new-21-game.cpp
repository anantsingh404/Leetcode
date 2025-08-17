class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
       int i;
        double ans;
        double Wsum;
        vector<double> dp(n + 1, 0.0);

        if (k == 0) {
            return 1.0;
        }

        if (n >= k - 1 + maxPts) {
            return 1.0;
        }

        dp[0] = 1.0;
        Wsum = 1.0;
        i = 1;

        while (i <= n) {
            dp[i] = Wsum / maxPts;

            if (i < k) {
                Wsum += dp[i];
            }

            if (i - maxPts >= 0) {
                if (i - maxPts < k) {
                    Wsum -= dp[i - maxPts];
                }
            }

            i++;
        }

        ans = 0.0;
        i = k;
        while (i <= n) {
            ans += dp[i];
            i++;
        }

        return ans;  
    }
};