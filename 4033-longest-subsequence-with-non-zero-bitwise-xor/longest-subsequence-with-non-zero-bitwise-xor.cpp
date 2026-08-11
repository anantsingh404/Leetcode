class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
      vector<int>dp(32,0);
      int maxi=0;
      for(int i=0;i<nums.size();i++)
      {
        int j=0;
        maxi=max(maxi,nums[i]);

        while(j<32)
        {
            if(nums[i]&(1<<j))
            {
                dp[j]++;
            }
            j++;
        }
      }
      if(maxi==0)
      {
        return 0;
      }
      int odd=0;
      for(int i=0;i<32;i++)
      {
        if(dp[i]%2)
        {
            ++odd;
        }
      } 
      if(odd)
      {
        return  nums.size();
      }
      if(nums.size()==1 && nums[0]==0)
      {
        return 0;
      }
       if(nums.size()==1)
      {
        return 0;
      }
      return  nums.size()-1;
    }
};