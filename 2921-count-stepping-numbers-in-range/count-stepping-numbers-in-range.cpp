class Solution {
public:
typedef long long ll;
const int  mod=1e9+7;
ll dp[101][2][2][11];

int n;
    ll solve(int idx,int zero,int tight,int prev,string &x)
    {
        if(idx==x.size())
        {   if(zero)
        {
            return 0;
        }
        return 1;
        }
        if(dp[idx][zero][tight][prev+1]!=-1)
        {
            return dp[idx][zero][tight][prev+1];
        }
        ll ans=0;
        ll limit=0;
        if(tight)
        {
            limit=x[idx]-'0';
        }
        else{
            limit=9;
        }
        for(int i=0;i<=limit;i++)
        {  
             int nt=tight;
        int nz=zero;
            if(tight && i<limit)
            {
                nt=0;
            }
            if(zero && i>0)
            {
                nz=0;
            }
            if(zero)
            {
                ans+=solve(idx+1,nz,nt,i,x);
                ans=ans%mod;
            }
            else
            {
              if(abs(i-prev)==1)
              {
                ans+=solve(idx+1,nz,nt,i,x);
                ans=ans%mod;
              }
            }
            

        }
        return dp[idx][zero][tight][prev+1]=ans%mod;


    }
    int countSteppingNumbers(string low, string high) {
      
      
       n=low.size();
      
       memset(dp,-1,sizeof(dp));
         ll xx=solve(0,1,1,-1,low);
      
         n=high.size();
          memset(dp,-1,sizeof(dp));
      ll yy=solve(0,1,1,-1,high);
      ll ans = yy - xx;
    ans %= mod;
        ans += mod;
        ans %= mod;
      ll add = true;
        for (ll i = 1; i < (ll) low.size(); i++)
            if (abs(low[i] - low[i - 1]) != 1) add = false;
        if (add) ans++;
        
        ans %= mod;
        return ans;
      return (yy-xx+mod)%mod;

    }
};