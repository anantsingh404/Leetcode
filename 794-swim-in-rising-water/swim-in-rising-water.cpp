class Solution {
public:
    int n,m;
    int arr[4]={-1,1,0,0};
    int brr[4]={0,0,-1,1};
    bool solve(int mid,vector<vector<int>>&grid)
    {
    vector<vector<int>>vis(n,vector<int>(m,0));
    priority_queue<pair<int,int>>pq;
     if(grid[0][0]>mid)
     {
        return false;
     }
     vis[0][0]=1;
     pq.push({0,0});
     while(!pq.empty())
     {
        pair<int,int>p=pq.top();
        int x=p.first;
        int y=p.second;
        pq.pop();
        for(int i=0;i<4;i++)
        {
            int p=x+arr[i];
            int q=y+brr[i];
            if(p>=0 && q>=0 && p<n && q<m && vis[p][q]==0 && grid[p][q]<=mid)
            {
                vis[p][q]=1;
                pq.push({p,q});
            }
        }
     }

      return vis[n-1][m-1]==1;
     }

    
    int swimInWater(vector<vector<int>>& grid) {
     int maxi=0;
     n=grid.size();
     m=grid[0].size();
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            maxi=max(maxi,grid[i][j]);
        }
     } 
     int mini=0;
     int ans=maxi;
     while(mini<=maxi)
     {
        int mid=(mini+maxi)/2;
        if(solve(mid,grid)){
            ans=mid;
            maxi=mid-1;
        }
        else
        {
            mini=mid+1;
        }
     } 
     return ans;
    }
};