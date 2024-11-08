class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mb) {
        int n=nums.size();

     vector<vector<int>>dp(n,vector<int>(32,0));
    for(int j=0;j<32;j++)
    {
        if((1<<j)&nums[0])
        {
            dp[0][j]++;
        }
    }
     for(int i=1;i<n;i++)
     {
        for(int j=0;j<32;j++)
        {
            if((1<<j)&nums[i])
        {
            dp[i][j]++;
        } 
        dp[i][j]+=dp[i-1][j];
        }
     }
     int x=pow(2,mb);
     vector<int>ans;
     for(int i=n-1;i>=0;i--)
     {   int temp=0;
        for(int j=mb-1;j>=0;j--)
        {
            if((temp|(1<<j))<x && dp[i][j]%2==0)
            {
                temp=temp|(1<<j);
            }
        }
        ans.push_back(temp);

     }
// reverse(ans.begin(),ans.end());
     return ans;
    }
};