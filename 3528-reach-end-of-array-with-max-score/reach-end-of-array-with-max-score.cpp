class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long>right(n,0);
         nums[n-1]=0;
        right[0]=1ll*nums[0];
       
        for(int i=1;i<n;i++)
        {
            right[i]=max(1ll*nums[i],right[i-1]);
        }
        int count=1;
        long long ans=0;
        int mini=0;
        for(int j=1;j<n;j++)
        {
            if(right[j]!=right[j-1])
            {
                ans+=(j-mini)*right[j-1];
                mini=j;
                cout<<ans<<endl;

            }
           
        }
        ans+=(n-mini-1)*right[n-1];
        return ans;
    }
};