class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       unordered_map<int,int>mp;
       int sum=0;
       int ans=0;
       int i=0;
       int j=0;
       int n=nums.size();
       while(i<n)
       {
        while(j<i && mp[nums[i]]>0)
        {
          --mp[nums[j]];
          sum-=nums[j];
          j++;
        }
        sum+=nums[i];
        mp[nums[i]]++;
        ans=max(ans,sum);
        i++;
       }
       return ans; 
    }
};