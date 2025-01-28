class Solution {
public:
int n;
int m;
int arr[4]={-1,1,0,0};
int brr[4]={0,0,-1,1};
int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis)
{
    if(i>=n || i<0 ||j>=m || j<0 || grid[i][j]==0)
    {
        return 0;
    }
    int sum=grid[i][j];
    vis[i][j]=1;
    for(int k=0;k<4;k++)
    {
        int x=i+arr[k];
        int y=j+brr[k];
        if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==0 && grid[x][y]>0)
        {
            sum+=solve(x,y,grid,vis);
        }
    }
    return sum;
}
    int findMaxFish(vector<vector<int>>& grid) {
     int ans=0;
     n=grid.size();
     m=grid[0].size();
     vector<vector<int>>vis(n,vector<int>(m,0));  
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
         if(grid[i][j]>0 && vis[i][j]==0)
         {
            ans=max(ans,solve(i,j,grid,vis));
         }
        }
     }
     return ans; 
    }
};