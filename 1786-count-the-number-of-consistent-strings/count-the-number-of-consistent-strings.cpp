class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
       vector<int>dp(36,0);
       for(int i=0;i<allowed.size();i++)
       {
        dp[allowed[i]-'a']++;
       } 
       int count=0;
       for(int i=0;i<words.size();i++)
       {
        bool ans=true;
        for(int j=0;j<words[i].size();j++)
        {
            if(dp[words[i][j]-'a']==0)
            {
                ans=false;
            }
        }
        if(ans)
        {
            ++count;
        }
       }
       return count;
    }
};