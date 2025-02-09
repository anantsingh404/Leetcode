class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
      int n=nums.size();  
      long long ans=0;
      for(int i=0;i<n;i++)
      {
        nums[i]=nums[i]-i;
      }
      unordered_map<int,int>mp;
      for(int i=0;i<n;i++)
      {
        ans+=i-mp[nums[i]];
        mp[nums[i]]++;
      }
      return ans;
    }
};