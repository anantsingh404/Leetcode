class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
      unordered_map<int,int>mp;
      int n=nums.size();
      long long ans=0;
      int j=0;
      long long sum=0;
      for(int i=0;i<n;i++) 
      {
        ++mp[nums[i]];
        sum+=nums[i];
        while(j<i && (mp[nums[i]]>1 || i-j+1>k))
        {
            --mp[nums[j]];
            sum-=nums[j];
            j++;
        }
       
        if(i-j+1==k)
        {
            ans=max(ans,sum);
        }

      }
      return ans;
    }
};