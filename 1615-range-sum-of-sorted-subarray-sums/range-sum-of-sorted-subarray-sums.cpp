class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>dp;
        for(int i=0;i<n;i++)
        {
          int sum=0;
          for(int j=i;j<n;j++)
          {
            sum+=nums[j];
            dp.push_back(sum);
          }  
        }
        sort(dp.begin(),dp.end());
        int ans=0;
        const int mod=1e9+7;
        for(int i=left-1;i<right;i++)
        {
            ans=(ans+dp[i])%mod;
        }
return ans;
    }
};