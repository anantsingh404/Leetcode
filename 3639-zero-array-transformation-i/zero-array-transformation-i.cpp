class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
      int n=nums.size();
      vector<int>dp(n+1,0);
      
      for(int i=0;i<q.size();i++)
      {
dp[q[i][0]]--;
dp[q[i][1]+1]++;
      }
      for(int i=1;i<n;i++)
      {
dp[i]=dp[i-1]+dp[i];
if(dp[i]+nums[i]>0)
{
    return false;
}
      } 
      if(dp[0]+nums[0]>0)
      {
        return false;
      }
      return true; 
    }
};