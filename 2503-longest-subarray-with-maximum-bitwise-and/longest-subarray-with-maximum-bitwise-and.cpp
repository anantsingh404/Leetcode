class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      vector<int>dp(32,0);
      int temp=0;
      int ans=0;
      for(int i=0;i<nums.size();i++)
      {
        int k=0;
        while(k<32)
        {
            if((1<<k)&nums[i])
            {
                dp[k]++;
            }
            else
            {
                dp[k]=0;
            }
            k++;
        }
        int p=0;
        while(dp[p]==0)
        {
            p++;
        }
        int mini=INT_MAX;
        for(int l=p;l<32;l++)
        {
            if(dp[l]>0)
            {
                mini=min(mini,dp[l]);
            }
        }
        int flag=0;
        int m=0;
        while(m<32)
        {
            if(dp[m])
            {
                flag=flag|(1<<m);
            }
            m++;
        }
        if(flag>temp)
        {   temp=flag;
            ans=mini;
        }
        //cout
        if(flag==temp)
        {
            ans=max(ans,mini);
        }
        //ans=max(ans)
      }
      return ans;
    }
};