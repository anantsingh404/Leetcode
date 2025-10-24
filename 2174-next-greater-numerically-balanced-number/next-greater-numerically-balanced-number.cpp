class Solution {
public:
    int nextBeautifulNumber(int n) {
      for(int i=n+1;i<=1e7;i++){
        string x=to_string(i);
        vector<int>dp(10,0);
        for(int j=0;j<x.size();j++){
            dp[x[j]-'0']++;
        }
        bool ans=true;
        for(int j=0;j<10;j++){
            if(dp[j]!=0 && j!=dp[j]){
                ans=false;
            }
        }
        if(ans)
        {
            return i;
        }

      } 
      return 0; 
    }
};