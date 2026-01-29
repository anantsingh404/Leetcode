class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& o, vector<char>& c, vector<int>& cost) {
       vector<vector<pair<long long,long long>>>adj(26); 
       vector<vector<long long>>dp(26,vector<long long>(26,INT_MAX));
       for(int i=0;i<o.size();i++)
       {
        long long x=o[i]-'a';
        long long y=c[i]-'a';
        long long co=cost[i];
        adj[x].push_back({y,co});
        dp[x][y]=min(dp[x][y],co);
       } 
       for(int k=0;k<26;k++)
       {
        for(int i=0;i<26;i++)
        {
             for(int j=0;j<26;j++)
             {
                if(dp[i][k]+dp[k][j]<dp[i][j])
                {
                    dp[i][j]=dp[i][k]+dp[k][j];
                }
             }
        }
       }
       long long count=0;
       for(int i=0;i<source.size();i++)
       {
        if(source[i]==target[i])
        {
            continue;
        }
        if(dp[source[i]-'a'][target[i]-'a']>=INT_MAX)
        {
            return -1;
        }
        count+=dp[source[i]-'a'][target[i]-'a'];
       }
       return count;
    }
};