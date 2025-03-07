class Solution {
public:
int n,m;
vector<vector<int>>dp;
int arr[4]={-1,1,0,0};
int brr[4]={0,0,-1,1};
int anss=0;
int solve(int i,int j,vector<vector<int>>&mat)
{
    if(i>=n || i<0 || j>=m || j<0)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans=0;
    for(int k=0;k<4;k++)
    {
        int x=arr[k]+i;
        int y=brr[k]+j;
        if(x>=0 && x<n && y>=0 && y<m && mat[x][y]>mat[i][j])
        {
            ans=max(ans,solve(x,y,mat));
        }
    }
    anss=max(anss,1+ans);
    return dp[i][j]=1+ans;
}
    int longestIncreasingPath(vector<vector<int>>& mat) {
       n=mat.size();
       m=mat[0].size();
       dp.assign(n,vector<int>(m,-1));
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(dp[i][j]==-1)
            {
              solve(i,j,mat);
            }
        }
       }
       return anss;
        
    }
};