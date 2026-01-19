class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int th) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Build 2D prefix sum
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] = mat[i][j];
                if(i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if(j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
                if(i > 0 && j > 0) {
                    dp[i][j] -= dp[i - 1][j - 1];
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int k = 0;
                while(i + k < n && j + k < m) {

                    int sum = dp[i + k][j + k];
                    if(i > 0) {
                        sum -= dp[i - 1][j + k];
                    }
                    if(j > 0) {
                        sum -= dp[i + k][j - 1];
                    }
                    if(i > 0 && j > 0) {
                        sum += dp[i - 1][j - 1];
                    }

                    if(sum <= th) {
                        ans = max(ans, k + 1);
                    }

                    k++;
                }
            }
        }

        return ans;
    }
};
