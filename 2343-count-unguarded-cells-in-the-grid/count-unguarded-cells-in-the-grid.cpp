class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
       vector<vector<int>>dp(m,vector<int>(n,0));
        for(auto itr:guards)
        {
            int x=itr[0];
            int y=itr[1];
            dp[x][y]++;
        }
         for(auto itr:walls)
        {
            int x=itr[0];
            int y=itr[1];
            dp[x][y]=-1;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==1)
                {
                    int x=i-1;
                    int y;
                    while(x>=0 && (dp[x][j]==0 ||dp[x][j]==2))
                    {
dp[x][j]=2;
--x;
                    }
                    x=i+1;
                    while(x<m && (dp[x][j]==0 ||dp[x][j]==2))
                    {
dp[x][j]=2;
++x;
                    }
                    y=j-1;
                     while(y>=0 && (dp[i][y]==0 ||dp[i][y]==2 ))
                    {
dp[i][y]=2;
--y;
                    }
                    y=j+1;
                      while(y<n &&(dp[i][y]==0 || dp[i][y]==2))
                    {
dp[i][y]=2;
++y;
                    }



                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==0)
                {
                    ++count;
                }
            }

        }
        return count;
    }
};