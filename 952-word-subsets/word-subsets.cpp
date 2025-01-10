class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
      vector<int>dp(26,0);
      for(int i=0;i<words2.size();i++)
      {  vector<int>flag(26,0);
        for(int j=0;j<words2[i].size();j++)
        {
             flag[words2[i][j]-'a']++;
             dp[words2[i][j]-'a']=max(dp[words2[i][j]-'a'],flag[words2[i][j]-'a']);
        }

      }
      vector<string>ans;
      for(int i=0;i<words1.size();i++)
      { 
        vector<int>temp(26,0);
        bool anss=true;
        for(int j=0;j<words1[i].size();j++)
        {
            temp[words1[i][j]-'a']++;
        }
        for(int k=0;k<26;k++)
        {
            if(temp[k]<dp[k])
            {
                anss=false;
            }
        }
        if(anss)
        {
            ans.push_back(words1[i]);
        }
      }
      return ans;  
    }
};