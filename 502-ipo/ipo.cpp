class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
     vector<pair<int,int>>dp;
     int n=profits.size();
     for(int i=0;i<n;i++)
     {
        dp.push_back({capital[i],profits[i]});
     }  
     sort(dp.begin(),dp.end()); 
     priority_queue<int>pq;
     int i=0;
     for(int j=0;j<k;j++)
     {
        while(i<n && dp[i].first<=w)
        {
            pq.push(dp[i].second);
            i++;
        }
        if(pq.empty())
        {
            break;
        }
        w+=pq.top();
        pq.pop();
     }
     return w;
    }
};