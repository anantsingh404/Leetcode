class Solution {
public:
    int longestNiceSubarray(vector<int>& a) {
     vector<int>dp(32,-1);
     int n=a.size();
     int ans=1;
     int k=-1;
     for(int i=0;i<n;i++)
     {
        int j=0;
        
        while(j<32)
        {
            if(a[i]&(1<<j))
            {
               
                if(dp[j]!=-1)
                {
                    k=max(k,dp[j]);
                    
                }
                dp[j]=i;
            }
           
            j++;
        }
        ans=max(ans,i-k);
     }
     return ans;

    }
};