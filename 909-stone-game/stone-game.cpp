class Solution {
public:
int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
{
    if(i==j)
    {
        return nums[j];
    }
    if(dp[i][j]!=INT_MIN)
    {
        return dp[i][j];
    }
    int p1=nums[i]-solve(i+1,j,nums,dp);
    int p2=nums[j]-solve(i,j-1,nums,dp);
    return dp[i][j]=max(p1,p2);
}
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
      return (int)solve(0,piles.size()-1,piles,dp)>0;  
    }
};