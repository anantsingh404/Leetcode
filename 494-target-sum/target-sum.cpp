class Solution {
public:
int solve(int idx,vector<int>&nums,vector<vector<int>>&dp,int sum)
{   
    if(idx>=nums.size() && sum==0)
    {
        return 1;
    }
    if(idx>=nums.size())
    {
        return 0;
    }
    
    if(dp[idx][sum]!=INT_MIN)
    {
        return dp[idx][sum];
    }
    int x=0,y=0;
    if(nums[idx]<=sum)
    {
        x=solve(idx+1,nums,dp,sum-nums[idx]);
    }
    y=solve(idx+1,nums,dp,sum);
    return dp[idx][sum]=x+y;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum-target)%2==1)
        {
            return 0;
        }
        if(abs(target)>sum)
        {
            return 0;
        }
        sum=(sum-target)/2;
       // sum=sum*2;
     vector<vector<int>>dp(n,vector<int>(sum+1,INT_MIN));
     return solve(0,nums,dp,sum);   
    }
};