class Solution {
public:
int arr[4]={-1,1,0,0};
int brr[4]={0,0,-1,1};

    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
         vector<vector<int>> seen(n, vector<int>(m, 0));
        seen[0][0] = 1;
        
        if(grid[0][1]>1 && grid[1][0]>1)
        {
            return -1;
        }
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
         pair<int,pair<int,int>>p=pq.top();
         int cost=p.first;
         int x=p.second.first;
         int y=p.second.second;
         pq.pop();
         if(x==n-1 && y==m-1)
         {
            return cost;
         }
         for(int i=0;i<4;i++)
         {
            int j=x+arr[i];
            int k=y+brr[i];
            if(j>=0 && k>=0 && j<n && k<m && !seen[j][k])
            {
                int waitTime = ((grid[j][k] - cost) % 2 == 0) ? 1 : 0;
                    int nextTime = max(cost + 1, grid[j][k] + waitTime);
              pq.push({nextTime,{j,k}});
              seen[j][k] = 1;

            }
           
         }
        }
        return -1;
    }
};