class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
      int n=nums.size();
      sort(nums.begin(),nums.end());
      int ans=0;
      for(int i=n-1;i>=2;i--)
      {
        if(nums[i-2]+nums[i-1]>nums[i])
        {
            ans=max(ans,nums[i-2]+nums[i-1]+nums[i]);
        }
      }
      return ans;

    }
};