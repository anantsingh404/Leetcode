class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n=nums.size();
      int sum=accumulate(nums.begin(),nums.end(),0);  
      unordered_map<int,int>mp;
      for(int i=0;i<n;i++)
      {
        mp[nums[i]]++;
      }
      int ans=INT_MIN;
      for(int i=-1000;i<=1000;i++)
      {
        int x=sum-i;
        int y=x-i;
        if(mp[i]>=1 && mp[y]>=1)
        {
            if(i==y && mp[i]>=2)
            {
                ans=max(ans,y);
            }
            else if(i!=y)
            {
                ans=max(ans,y);
            }
        }
      }
return ans;

    }
};