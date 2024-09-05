class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
      int m=rolls.size();
      int sum=accumulate(rolls.begin(),rolls.end(),0);
    
      int x=(n+m)*(mean)-sum;
      if(x<=0)
      {
        return  {};
      }
      vector<int>dp(n,1);
      if((6*n)<x || x<n)
      {
        return {};
      }
      x-=n;

      cout<<x<<endl;
      int i=0;
      while(i<n && x)
      {
       if(dp[i]<6)
       {
        dp[i]=min(6,x+dp[i]);
        x-=dp[i]-1;
        
        cout<<x<<endl;
        if(x==0)
        {
            return dp;
        }
        

       }
       i++;
      }
      return dp;  
    }
};