class Solution {
public:
int arr[4]={-1,1,0,0};
int brr[4]={0,0,-1,1};
int arr1[4]={-2,2,0,0};
int brr1[4]={0,0,-2,2};
    int minTimeToReach(vector<vector<int>>& mt) {
      int n=mt.size();
      int m=mt[0].size();
      vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
      dp[0][0]=0;
      priority_queue<pair<int,pair<int,pair<int,int>>>,vector<pair<int,pair<int,pair<int,int>>>>,greater<pair<int,pair<int,pair<int,int>>>>>pq;
      pq.push({0,{1,{0,0}}});
      while(!pq.empty())
      {
        auto itr=pq.top();
        pq.pop();
        int time=itr.first;
        int x=itr.second.second.first;
        int y=itr.second.second.second;
        int turn=itr.second.first;
        if(x==n-1 && y==m-1)
        {
            return time;
        }
        for(int i=0;i<4;i++)
        {
            int p=x+arr[i];
            int q=y+brr[i];
            if(p>=0 && p<n && q>=0 && q<m && turn==1)
            {
                if(dp[p][q]>time+1)
                {    int xx=max(mt[p][q]+1,time+1);
                    dp[p][q]=xx;
                    pq.push({xx,{2,{p,q}}});
                }
            }
            else if(p>=0 && p<n && q>=0 && q<m && turn==2)
            {
                if(dp[p][q]>time+2)
                {    int xx=max(mt[p][q]+2,time+2);
                    dp[p][q]=xx;
                    pq.push({xx,{1,{p,q}}});
                }
            }
            
         
        }

      }
      return dp[n-1][m-1];

      
    }
};