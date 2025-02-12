class Solution {
public:
    int maximumSum(vector<int>& nums) {
      unordered_map<int,vector<int>>mp;
      for(int i=0;i<nums.size();i++)
      {
        int x=nums[i];
        int sum=0;
        while(x)
        {
            sum+=x%10;
            x=x/10;
        }
        mp[sum].push_back(nums[i]);
      }
      int ans=-1;
      for(auto itr:mp)
      {
        sort(itr.second.begin(),itr.second.end());
        if(itr.second.size()>1)
        {
            ans=max(ans,itr.second[itr.second.size()-2]+itr.second[itr.second.size()-1]);
        }
      } 
      return ans; 
    }
};