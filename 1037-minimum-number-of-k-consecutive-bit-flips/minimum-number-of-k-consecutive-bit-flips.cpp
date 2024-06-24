class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
       vector<int>dp(n+1,0);
       int count=0;
       int prev=0;
       for(int i=0;i<=n-k;i++)
       { 
        dp[i]=dp[i]+prev;
        cout<<dp[i]<<endl;
        if(nums[i]==0 && dp[i]%2==0)
        {  
            nums[i]=1;
            ++dp[i];
        
            prev=dp[i];
            ++count;
            --dp[i+k];
        }
        else if(nums[i]==1 && dp[i]%2)
        {
            ++dp[i];
            ++count;
             prev=dp[i];
            --dp[i+k];
        }
        else
        {
            prev=dp[i];
        }
       }
       for(int i=n-k+1;i<n;i++)
       {
        dp[i]=dp[i]+prev;
        if(nums[i]==0 && dp[i]%2==0)
        {
            return -1;
        }
        if(nums[i]==1 && dp[i]%2)
        {
            return -1;
        }
        prev=dp[i];
       }
       
return count;
    }
};