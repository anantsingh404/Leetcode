class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int count=0;
      vector<int>dp(2*1e5+1,0);
      unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++)
      {
        while(dp[nums[i]]!=0)
        {
         nums[i]++;
         ++count;
        }
        dp[nums[i]]=1;
      }
      return count;
    }
};