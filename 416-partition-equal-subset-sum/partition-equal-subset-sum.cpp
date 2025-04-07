class Solution {
public:
int n;
int sum=0;
bool res=false;
int solve(int idx,vector<int>&nums,vector<vector<int>>&dp,int s)
{   if(res)
{
    return 1;
}
    if(idx>=n &&  s==sum )
    {
        return 1;
    }
    if(idx>=n || s>sum) 
    {
        return 0;
    }
    if(dp[idx][s]!=-1)
    {
        return dp[idx][s];
    }
    int ans=0;
    ans=ans|solve(idx+1,nums,dp,s+nums[idx]);
    ans=ans|solve(idx+1,nums,dp,s);
    if(ans==1)
    {
        res=true;
    }
    return dp[idx][s]=ans;
    
}
    bool canPartition(vector<int>& nums) {
        sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2)
        {
            return false;
        }
        sum=sum/2;
        n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        solve(0,nums,dp,0);
        return res;

    }
};