class Solution {
public:
    int maximumLengthSubstring(string s) {
      int j=0;
      int n=s.size();
      int ans=1;
      vector<int>dp(26,0);
      for(int i=0;i<n;i++)
      {
        dp[s[i]-'a']++;
        while(dp[s[i]-'a']>2 && j<n)
        {
            --dp[s[j]-'a'];
            j++;
        }
        ans=max(ans,i-j+1);
       // cout<<ans<<endl;
      } 
      return ans; 
    }
};