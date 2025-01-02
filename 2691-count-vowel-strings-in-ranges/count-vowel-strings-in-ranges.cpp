class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
       int n=words.size();
       vector<int>dp(n,0);
       int count=0;
       for(int i=0;i<n;i++)
       {
           char x=words[i][0];
           char y=words[i][words[i].size()-1];
           bool ans=true;
           if(x!='a' && x!='e' && x!='i' && x!='o' && x!='u')
           {
            ans=false;
           }
            if(y!='a' && y!='e' && y!='i' && y!='o' && y!='u')
           {
            ans=false;
           }
           if(ans)
           {
            ++count;
           }
           dp[i]=count;
       }
       vector<int>ans;
       for(int i=0;i<queries.size();i++)
       {
        int x=queries[i][0];
        int y=queries[i][1];
        if(x>0)
        {
            ans.push_back(dp[y]-dp[x-1]);
        }
        else
        {
            ans.push_back(dp[y]);
        }
       }
       return ans;

    }
};