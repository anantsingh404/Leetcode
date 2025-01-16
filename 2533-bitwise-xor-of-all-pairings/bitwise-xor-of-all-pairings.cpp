class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
      vector<int>dp1(32,0);
      vector<int>dp2(32,0);
      for(int i=0;i<nums1.size();i++)
      {
        int j=0;
        while(j<32)
        {
            if(nums1[i]&(1<<j))
            {
                dp1[j]++;
            }
            j++;
        }
      } 
      for(int i=0;i<nums2.size();i++)
      {
        int j=0;
        while(j<32)
        {
            if(nums2[i]&(1<<j))
            {
                dp2[j]++;
            }
            j++;
        }
      }
      vector<int>dp(32,0);
      int n=nums1.size();
      int m=nums2.size();
      int ans=0;
      for(int i=0;i<32;i++)
      {
        int x=dp1[i];
        int y=n-dp1[i];
        int p=dp2[i];
        int q=m-dp2[i];
        dp[i]=x*q+p*y;
        if(dp[i]%2)
        {
            ans=ans|(1<<i);
        }
      } 
      return ans;

    }
};