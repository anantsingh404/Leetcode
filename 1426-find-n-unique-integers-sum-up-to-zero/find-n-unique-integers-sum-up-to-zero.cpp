class Solution {
public:
    vector<int> sumZero(int n) 
    {  vector<int>dp(n,0);
    int sum=0;
       for(int i=0;i<n-1;i++)
       {
        dp[i]=i+1;
        sum+=dp[i];
       } 
       dp[n-1]=-1*sum;
       return dp;
    }
};