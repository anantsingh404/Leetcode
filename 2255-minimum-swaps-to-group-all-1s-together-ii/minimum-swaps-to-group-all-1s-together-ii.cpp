class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++)
        {
    if( nums[i]==1)

    {
        ++count;
    }
    dp[i]=count;
        }
        int sum=0;int i=0;
        while(i<count)
        {
         if(nums[i]==1)
         {
            ++sum;
         }
         i++;
        }
        int ans=INT_MAX;
        ans=min(ans,count-sum);
        int j=0;
        while(i<n)
        {
          if(nums[i]==1)
          {
            ++sum;
          }
          if(nums[j]==1)
          {
            --sum;
          }
          ans=min(ans,count-sum);
          i++;
          j++;

        }
        for(int i=0;i<count;i++)
        {
            ans=min(ans,count-dp[i]-(dp[n-1]-dp[n-(count-i)]));
        }
        
        return ans;
    }
};