class Solution {
public:
    int maxDifference(string s) {
       vector<int>dp(26,0);
       int maxi=INT_MIN;
       int mini=INT_MAX;
       for(int i=0;i<s.size();i++)
       {
        dp[s[i]-'a']++;
       }
       for(int i=0;i<26;i++)
       {
    if(dp[i]%2)
    {
        maxi=max(maxi,dp[i]);
    }
    else
    {
        if(dp[i]>0)
        {
            mini=min(mini,dp[i]);
        }
    }
       } 
       return maxi-mini;
    }
};