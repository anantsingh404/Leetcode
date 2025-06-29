class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
     sort(nums.begin(),nums.end());
     int n=nums.size();
     const int mod=1e9+7;
     vector<int>dp(1e5+1,0);
     dp[0]=1;
     for(int i=1;i<=1e5;i++)
     {
        dp[i]=(dp[i-1]*2)%mod;
     }
    
     long long ans=0;
     for(int i=0;i<n;i++)
     {
        int idx=upper_bound(nums.begin()+i,nums.end(),target-nums[i])-nums.begin();
        --idx;
        if(idx>=i)
        {
            ans=(ans+dp[idx-i])%mod;
        }

     }  
     return (int)ans%mod; 
    }
};