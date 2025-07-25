class Solution {
public:
    int maxSum(vector<int>& nums) {
      int sum=0;
      unordered_map<int,int>mp;
      int maxi=INT_MIN;
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]>0 && mp[nums[i]]<1)
        {
            sum+=nums[i];
            mp[nums[i]]++;
        }
        maxi=max(maxi,nums[i]);
       
      }  
       if(sum==0)
        {
            return maxi;
        }
        return sum;
    }
};