class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        vector<int>dp(n,0);
        priority_queue<int,vector<int>,greater<int>>avl;
        for(int i=0;i<n;i++)
        {
            avl.push(i);
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        sort(meet.begin(),meet.end());
    for(int i=0;i<meet.size();i++)
    { 
        while(!pq.empty() && pq.top().first<=meet[i][0])
      {
        int x=pq.top().second;
        avl.push(x);
        pq.pop();
      }

      if(!avl.empty())
      {
          int x=avl.top();
          avl.pop();
          pq.push({meet[i][1],x});
          dp[x]++;
      }
      else
      {
          auto top=pq.top();
          int maxi=top.first;
          int ind=top.second;
          dp[ind]++;
          pq.pop();
          pq.push({top.first+meet[i][1]-meet[i][0],ind});
      }
    }
    return  max_element(dp.begin(),dp.end())-dp.begin();
    
    }
};