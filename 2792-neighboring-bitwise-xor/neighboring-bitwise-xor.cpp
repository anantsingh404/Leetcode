class Solution {
public:
    bool doesValidArrayExist(vector<int>& der) {
            int n=der.size();
            vector<int>dp(n,0);
            dp[0]=0;
            
            for(int i=0;i<n-1;i++)
            {
                if(der[i]==0)
                {
                    dp[i+1]=(dp[i]==0)?0:1;
                }
                else
                {
                   dp[i+1]=(dp[i]==0)?1:0;
                }
            }
            bool ans=true;
            for(int i=0;i<n-1;i++)
            {
                if(dp[i]^dp[i+1]!=der[i])
                {
                    ans=false;
                    break;
                }
            }
            if(dp[n-1]^dp[0]!=der[n-1])
            {
                ans=false;
            }
            if(ans)
            {
                return true;
            }
            
            dp[0]=1;
            for(int i=1;i<n-1;i++)
            {
                if(der[i]==0)
                {
                    dp[i+1]=(dp[i]==0)?0:1;
                }
                else
                {
                   dp[i+1]=(dp[i]==0)?1:0;
                }
            }
            ans=true;
            for(int i=0;i<n-1;i++)
            {
                if(dp[i]^dp[i+1]!=der[i])
                {
                    ans=false;
                    break;
                }
            }
            if(dp[n-1]^dp[0]!=der[n-1])
            {
                ans=false;
            }
            if(ans)
            {
                return true;
            }

        
       return false;
    }
};