class Solution {
public:
int arr[4]={-1,1,0,0};
int brr[4]={0,0,-1,1};
    int minimumObstacles(vector<vector<int>>&grid) {
        int n=grid.size();
        int m=grid[0].size();
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       pq.push({0,{0,0}});
         vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        dp[0][0]=0;
       while(!pq.empty())
       {
         pair<int,pair<int,int>>p=pq.top();
         int cost=p.first;
         int x=p.second.first;
         int y=p.second.second;
         pq.pop();
         for(int k=0;k<4;k++)
         {
            int i=x+arr[k];
            int j=y+brr[k];

            if(i>=0 && j>=0 && i<n && j<m)
            {   
                if(dp[i][j]>cost+grid[i][j])
                {
                    dp[i][j]=cost+grid[i][j];
                    pq.push({dp[i][j],{i,j}});
                }
            }
         }
         



       }
       return dp[n-1][m-1];

    }
};