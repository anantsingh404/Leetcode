class Solution {
public:
int arr[4]={-1,1,0,0};
int brr[4]={0,0,-1,1};
bool solve(int i,int j,vector<vector<int>>&grid2,vector<vector<int>>&grid1)
{
    bool ans=true;
    if(grid2[i][j]==1 && grid1[i][j]==0)
    {
        ans=false;
    }
    grid2[i][j]=0;
    for(int k=0;k<4;k++)
    {
        int x=arr[k]+i;
        int y=brr[k]+j;
        if(x>=0 && x<grid1.size() && y>=0 && y<grid1[0].size() && grid2[x][y]==1)
        {
            ans&=solve(x,y,grid2,grid1);
        }
    }
    return ans;
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1)
                {
                    if(solve(i,j,grid2,grid1))
                    {
                        ++count;
                    }
                }
            }
        }
return count;
    }
};