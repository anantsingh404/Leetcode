class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
      vector<vector<int>>dp(k,vector<int>(k,0));
      int maxi=1;
      for(int num:nums)
      {
        int cn=num%k;
        for(int mod=0;mod<k;mod++)
        {
            int pn=(mod-cn+k)%k;

            dp[cn][mod]=max(dp[cn][mod],1+dp[pn][mod]);
            maxi=max(maxi,dp[cn][mod]);

        }
      }
      return maxi;
    }
};