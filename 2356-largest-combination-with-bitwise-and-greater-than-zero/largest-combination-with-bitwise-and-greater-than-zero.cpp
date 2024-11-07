class Solution {
public:
    int largestCombination(vector<int>& cand) {
        int n=cand.size();
     vector<int>dp(32,0);
     for(int i=0;i<n;i++)
     {
        int j=0;
        int x=cand[i];
        while(j<32 )
        {  if (((1<<j)&x) >0)
           {
            dp[j]=dp[j]+1;
            }
            ++j;
        }
     }
     
     int ans=0; 
     for(int i=0;i<32;i++)
     {
        ans=max(ans,dp[i]);
     }
     return ans;  
    }
};