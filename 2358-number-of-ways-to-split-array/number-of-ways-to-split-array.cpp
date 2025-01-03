class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
      long long sum=0;
      int n=nums.size();
      vector<long long>dp(n,0);
      for(int i=n-1;i>=0;i--)
      {
        sum+=nums[i];
        dp[i]=sum;
      }
      int count=0;
      sum=0;
      for(int i=0;i<n-1;i++)
      {
        sum+=nums[i];
        if(sum>=dp[i+1])
        {
            ++count;
        }
      }
      return count;  
    }
};