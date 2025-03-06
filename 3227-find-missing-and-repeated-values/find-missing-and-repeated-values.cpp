class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<int>ans;
    vector<int>dp(n*n+1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[grid[i][j]]++;
            if(dp[grid[i][j]]==2)
            {
                ans.push_back(grid[i][j]);
            }
        }
    }
    for(int i=1;i<=n*n;i++)
    {
        if(dp[i]==0)
        {
            ans.push_back(i);
        }
    }
    return ans;

    }
};