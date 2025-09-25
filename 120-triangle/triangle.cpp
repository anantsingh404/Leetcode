class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;++i){
            for(int j=0;j<=i;j++){
                if(j==0) dp[i][j]=dp[i-1][j]+triangle[i][j];
                else if(j==i) dp[i][j]=dp[i-1][j-1]+triangle[i][j];
                else dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        int minDis=INT_MAX;
        for(int i=0;i<n;i++){
            minDis=min(minDis,dp[n-1][i]);
        }
        return minDis; 
    }
};