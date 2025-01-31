class Solution {
public:
int arr[4]={-1,1,0,0};
int brr[4]={0,0,1,-1};
vector<vector<int>>vis;
 unordered_map<int,int>mp;
 int bfs(int i,int j,vector<vector<int>>&grid,int type)
 {  int n=grid.size();
 int m=grid[0].size();
    queue<pair<int,int>>q;
    int count=1;
    q.push({i,j});
    grid[i][j]=type;
    while(!q.empty())
    {
        pair<int,int>x=q.front();
        q.pop();
        int a=x.first;
        int b=x.second;
        for(int k=0;k<4;k++)
        {
            int p=a+arr[k];
            int qq=b+brr[k];
            if(p>=0 && p<n && qq>=0 && qq<m && vis[p][qq]==0 && grid[p][qq]==1)
            {
                 grid[p][qq]=type;
                // pair<int,int>pp={p,q};
                 q.push({p,qq});
                 ++count;
                 vis[p][qq]=1;
            }
        }
    }
    mp[type]=count;
    return count;
 }
    int largestIsland(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vis.assign(n,vector<int>(m,0));
     int type=2;
     int ans=1;
    for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
         {
            if(grid[i][j]==1 && vis[i][j]==0)
            {
                int x=bfs(i,j,grid,type);
                ans=max(ans,x);
                ++type;

            }
         }
      }
      for(int i=0;i<n;i++)
      { 
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==0)
            {
set<int>st;
for(int k=0;k<4;k++)
{
    int x=i+arr[k];
    int y=j+brr[k];
    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]>=2)
    {
        st.insert(grid[x][y]);
    }
    int sum=0;
    for(int itr:st)
    {
        sum+=mp[itr];
    }
    ans=max(ans,sum+1);
}
        }
      }
      }
      return ans;  
    }
};