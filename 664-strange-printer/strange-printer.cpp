class Solution {
public:
int solve(int i,int j,string &s,vector<vector<int>>&dp)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    char x=s[i];
    int ans=1+solve(i+1,j,s,dp);
    for(int k=i+1;k<=j;k++)
    {
       if(s[k]==x)
       {
        int flag=solve(i,k-1,s,dp)+solve(k+1,j,s,dp);
        ans=min(ans,flag);
       }
    }
    return dp[i][j]=ans;

}
    int strangePrinter(string s) {
        string temp;
        int i=0;;
        while(i<s.size())
        {
            if(temp.empty() || temp.back()!=s[i])
            {
                temp.push_back(s[i]);
            }
            i++;
        }
        int n=temp.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0,n-1,temp,dp);


    }
};