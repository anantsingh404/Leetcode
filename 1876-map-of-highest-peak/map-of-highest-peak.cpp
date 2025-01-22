class Solution {
public:
int arr[4]={-1,1,0,0};
int brr[4]={0,0,-1,1};
    vector<vector<int>> highestPeak(vector<vector<int>>& iw) {
        int n=iw.size();
        int m=iw[0].size();
     queue<pair<int,int>>pq;
     vector<vector<int>>vis(n,vector<int>(m,0));
      vector<vector<int>>height(n,vector<int>(m,0));
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            if(iw[i][j]==1)
            {
                height[i][j]=0;
                vis[i][j]=1;
                pq.push({i,j});

            }
            
        }
     }
     int maxi=0;
        while(!pq.empty())
        {
           pair<int,int>x=pq.front();
           pq.pop();
           int a=x.first;
           int b=x.second;
           for(int i=0;i<4;i++)
           {
            int p=a+arr[i];
            int q=b+brr[i];
            if(p>=0 && p<n && q>=0 && q<m && vis[p][q]==0)
            {
                height[p][q]=height[a][b]+1;
                maxi=max(maxi,height[p][q]);
                vis[p][q]=1;
                pq.push({p,q});
            }
           }

        }
        return height;

       
    }
};