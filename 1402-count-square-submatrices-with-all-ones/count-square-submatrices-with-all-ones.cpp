class Solution {
public:
int n,m;
int solve(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp)
{
    if(i>=n || j>=m)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(mat[i][j]==0)
    {
        return 0;
    }
    int sum=0;
    int a=solve(i+1,j,mat,dp);
    int b=solve(i+1,j+1,mat,dp);
    int c=solve(i,j+1,mat,dp);
    return dp[i][j]=1+min(min(a,b),c);

}
    int countSquares(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
     vector<vector<int>>dp(n,vector<int>(m,-1));
     int sum=0;
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            sum+=solve(i,j,mat,dp);
        }
     }
     return sum;


    }
};