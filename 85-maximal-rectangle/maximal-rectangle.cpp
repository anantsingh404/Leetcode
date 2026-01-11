class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
        dp[0][j]=mat[0][j]-'0';
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='1')
                {
                    dp[i][j]=dp[i-1][j]+1;
                }
                else
                {
                    dp[i][j]=0;
                }

            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                int mini=n;
                for(int k=j;k<m;k++)
                {
                  mini=min(mini,dp[i][k]);
                  ans=max(ans,mini*(k-j+1));
                }
            }
        }
        return ans;   
    }
};