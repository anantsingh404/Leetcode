class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(sqrt(nums[i]))!=mp.end() && sqrt(nums[i])*sqrt(nums[i])==nums[i])
            {
                int x=sqrt(nums[i]);
                if(x*x==nums[i])
                {
                    ans=max(ans,mp[x]+1);
                    mp[nums[i]]=ans;
                }
            }
            else
            {
                mp[nums[i]]=1;
            }
        }
        if(ans<2)
        {
            return -1;
        }
        return ans;
        
    }
};