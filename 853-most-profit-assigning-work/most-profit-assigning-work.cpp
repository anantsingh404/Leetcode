class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
     // int i=0;
      int j=0;
      vector<pair<int,int>>dp;
      for(int i=0;i<profit.size();i++)
      {
        dp.push_back({difficulty[i],profit[i]});
      }
      sort(dp.begin(),dp.end()); 
      for(int i=1;i<dp.size();i++)
      {
        
            dp[i].second=max(dp[i].second,dp[i-1].second);
      }
      
      sort(worker.begin(),worker.end());
      int n=worker.size(); 
      int sum=0;
        j=dp.size()-1;
      for(int i=n-1;i>=0;i--)
      {
        while(j>=0 && dp[j].first>worker[i])
        {
            
            --j;
        }
        if(j>=0){
        sum+=dp[j].second;
        }
        if(j<0)
        {
            return sum;
        }
      }
      return sum;
    }
};