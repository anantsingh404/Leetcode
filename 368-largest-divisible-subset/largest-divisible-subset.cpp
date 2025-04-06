class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      int n=nums.size();
      sort(nums.begin(),nums.end());
      vector<vector<int>>dp(n);
      for(int i=0;i<n;i++)
      {
        dp[i].push_back(nums[i]);
      }
      int anss=1;
      for(int i=1;i<n;i++)
      {
        for(int j=0;j<i;j++)
        {
            if(nums[i]%dp[j].back()==0 && dp[j].size()+1>dp[i].size())
            {   
                dp[i]=dp[j];
                dp[i].push_back(nums[i]);
                    int x=dp[i].size();
                    anss=max(anss,x);
            }
        }
      }
      for(int i=0;i<n;i++)
      {
        if(dp[i].size()==anss)
        {
            return dp[i];
        }
      }
return {};

    }
};