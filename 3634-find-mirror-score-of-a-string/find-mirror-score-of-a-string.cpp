class Solution {
public:
    long long calculateScore(string s) {
     long long ans=0;
    // vector<int>vis(n,0);
    int n=s.size();
     vector<vector<int>>dp(26);
     dp[s[0]-'a'].push_back(0);
     for(int i=1;i<s.size();i++)
     {
        int x=s[i]-'a'+1;
        int y=26-x;
        if(!dp[y].empty())
        {
            ans+=(i-dp[y].back());
            dp[y].pop_back();
        }
        else
        {
             dp[s[i]-'a'].push_back(i);
        }

     }  
     return ans; 
    }
};