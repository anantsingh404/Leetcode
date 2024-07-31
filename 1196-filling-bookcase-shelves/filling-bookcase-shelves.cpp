class Solution {
public:
int n;
int solve(int idx,int &sw,vector<vector<int>>&books,vector<int>&dp)
{
    if(idx>=n)
    {
        return 0;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    int mini=0;
    int sum=0;
    int ans=INT_MAX;
    for(int i=idx;i<n;i++)
    {
      
       if(sum+books[i][0]<=sw)
       {
           sum+=books[i][0];
           mini=max(mini,books[i][1]);
           ans=min(ans,mini+solve(i+1,sw,books,dp));
       }
       else
       {
          break;
       }
    }
    return dp[idx]=ans;
}
    int minHeightShelves(vector<vector<int>>& books, int sw) {
        n=books.size();
     vector<int>dp(n+1,-1);  
     return solve(0,sw,books,dp); 
    }
};