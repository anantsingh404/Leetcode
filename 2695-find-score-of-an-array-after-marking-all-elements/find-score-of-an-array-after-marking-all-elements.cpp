class Solution {
public:
    long long findScore(vector<int>& nums) {
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     int n=nums.size();
     vector<int>vis(n,0); 
     for(int i=0;i<n;i++)
     {
        pq.push({nums[i],i});
     }
     long long sum=0;
     int c=0;
     while(!pq.empty())
     {
        auto x=pq.top();
        if(vis[x.second]==1)
        {
            pq.pop();
            continue;
        }
        if(vis[x.second]==0)
        {    vis[x.second]=1;
            sum+=x.first;
        }
        if(x.second+1<n)
        {
            vis[x.second+1]=1;
        }
         if(x.second-1>=0)
        {
            vis[x.second-1]=1;
        }
        cout<<sum<<endl;
        pq.pop();

     }
     return sum;

    }
};