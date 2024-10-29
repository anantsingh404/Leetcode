class Solution {
public:
int arr[3]={-1,0,1};
int brr[3]={1,1,1};
int n,m;
vector<vector<int>>dp;

int solve(int i,int j,vector<vector<int>>&grid)
{   
    
     if(dp[i][j]!=-1)
     {
        return dp[i][j];
     }
    int ans=0;
    for(int k=0;k<3;k++)
    {
        int x=i+arr[k];
        int y=j+brr[k];
        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]>grid[i][j])
        {
           ans=max(ans,(1+solve(x,y,grid)));
        }
    }
    return dp[i][j]= ans;
}
    int maxMoves(vector<vector<int>>& grid) {
      int maxi=0;
      n=grid.size();
      m=grid[0].size();
      dp.assign(n,vector<int>(m,-1));
      for(int i=0;i<n;i++)
      { 
        
         int x=solve(i,0,grid);
         maxi=max(maxi,x);
      }  
      return maxi;
    }
};