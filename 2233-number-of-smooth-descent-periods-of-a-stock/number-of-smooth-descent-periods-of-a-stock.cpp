class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
       int n=prices.size();
       vector<long long>dp(n,0);
       dp[n-1]=1;
       for(int i=n-2;i>=0;i--)
       {
        if(prices[i]==(prices[i+1]+1))
        {
            dp[i]=dp[i+1]+1;
        }
        else
        {
            dp[i]=1;
        }
       }
       long long count=0;
       for(int i=0;i<n;i++)
       {
        count+=dp[i];
       }
       return count;
       

    }
};