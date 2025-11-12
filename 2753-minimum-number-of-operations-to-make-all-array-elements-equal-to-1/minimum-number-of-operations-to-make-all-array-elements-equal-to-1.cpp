class Solution {
public:
    int minOperations(vector<int>& nums) {
      int one=0;
      int gcd=0;
      int n=nums.size();
      int g=nums[n-1];
      for(int i=0;i<n-1;i++)
      {  g=__gcd(g,nums[i]);
        if(nums[i]==1)
        {
            ++one;
        }
        if(__gcd(nums[i],nums[i+1])==1)
        {
            ++gcd;
        }
      }
      if(nums[n-1]==1)
      {
        ++one;
      }
      if(g>1)
      {
        return -1;
      }
      if(one)
      {
        return n-one;
      }
      if(gcd)
      {
        return n-one;
      }
      int ans=n;
      for(int i=0;i<n;i++)
      {  int flag=nums[i];
        for(int j=i;j<n;j++)
        {
            flag=__gcd(flag,nums[j]);
            if(flag==1)
            {
                ans=min(ans,j-i+1);
            }
        }
      }
      return n+(ans-2);
      return 0;

    }
};