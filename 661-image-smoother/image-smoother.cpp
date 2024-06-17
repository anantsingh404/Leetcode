class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
      int n=img.size();
      int m=img[0].size();
      vector<vector<int>>dp(n,vector<int>(m,0));
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            int sum=0;
            int count=1;
            sum+=img[i][j];
            if(i-1>=0)
            {
                ++count;
                sum+=img[i-1][j];
            }
            if(j-1>=0)
            {
                ++count;
                sum+=img[i][j-1];
            }
            if(i+1<n)
            {
                ++count;
                sum+=img[i+1][j];
            }
            if(j+1<m)
            {
                ++count;
                sum+=img[i][j+1];
            }
            if(i-1>=0 && j-1>=0)
            {
                ++count;
                sum+=img[i-1][j-1];
            }
            if(i-1>=0 && j+1<m)
            {
                ++count;
                sum+=img[i-1][j+1];
            }
            if(i+1<n && j-1>=0)
            {
                ++count;
                sum+=img[i+1][j-1];
            }
            if(i+1<n && j+1<m)
            {
                ++count;
                sum+=img[i+1][j+1];
            }
            dp[i][j]=floor(sum/count);
        }
      }
      return dp;
    }
};