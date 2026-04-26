class Solution {
    boolean flag;
    int n,m;
    int [] arr={-1,1,0,0};
    int [] brr={0,0,-1,1};
    private void solve(int i,int j,int p,int q,int par,int [][]grid,int [][]vis)
    {
         if(i<0 || j<0 || i>=n || j>=m || par!=grid[i][j] || vis[i][j]==1 || flag==true)
         {
            return;
         }
         if(vis[i][j]==2)
         {
            flag=true;
            return;
         }
         vis[i][j]=2;
         for(int k=0;k<4;k++)
         {
            int x=i+arr[k];
            int y=j+brr[k];
            if(x>=0 && x<n && y>=0 && y<m && vis[x][y]!=1 && (x!=p || y!=q))
            {
                solve(x,y,i,j,grid[i][j],grid,vis);
            }
         }
         vis[i][j]=1;

    }
    public boolean containsCycle(char[][] g) {
      n=g.length;
      m=g[0].length;
      flag=false;
      int vis[][]=new int[n][m];
       int grid[][]=new int[n][m];
        for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            grid[i][j]=g[i][j]-'a';
        }
      }
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            vis[i][j]=0;
        }
      }

      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]==0)
            {
                 solve(i,j,-1,-1,grid[i][j],grid,vis);
            }
        }
      }
      return flag;
    }
}