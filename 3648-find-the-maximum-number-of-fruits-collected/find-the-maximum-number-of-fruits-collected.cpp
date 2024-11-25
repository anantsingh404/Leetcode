class Solution
{
public:
    int dp[1001][1001]; 
    int recur_BL(int i, int j, vector<vector<int> > &fruits, int n)
    {
        if (i < 0 or j < 0 or i >= n or j >= n)
            return -1e9;

        if (i == n - 1 and j == n - 1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int op1 = fruits[i][j] + recur_BL(i - 1, j + 1, fruits, n);
        int op2 = fruits[i][j] + recur_BL(i, j + 1, fruits, n);
        int op3 = fruits[i][j] + recur_BL(i + 1, j + 1, fruits, n);
        return dp[i][j] = max({op1, op2, op3});
    } // n^2

    int recur_TR(int i, int j, vector<vector<int> > &fruits, int n)
    {
        if (i < 0 or j < 0 or i >= n or j >= n)
            return -1e9;

        if (i == n - 1 and j == n - 1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int op1 = fruits[i][j] + recur_TR(i + 1, j - 1, fruits, n);
        int op2 = fruits[i][j] + recur_TR(i + 1, j, fruits, n);
        int op3 = fruits[i][j] + recur_TR(i + 1, j + 1, fruits, n);

        return dp[i][j] = max({op1, op2, op3});
    } 
     
    int maxCollectedFruits(vector<vector<int> > &fruits)
    {
        int n = fruits.size();
        int ans = 0;
        for (int i = 0; i < n; i++) // n
        {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }
        memset(dp, -1, sizeof dp);
        ans += recur_BL(n - 1, 0, fruits, n);
        memset(dp, -1, sizeof dp);
        ans += recur_TR(0, n - 1, fruits, n); 

        return ans;
    }
};

