class Solution {
public:
const int mod=1e9+7;
long long exponent(long long base,long long expo)
{    if(expo==0)
{
    return 1;
}
    
    long long x=exponent(base,expo/2);
    if(expo%2)
    {
        return ((x*x)%mod*base)%mod;
    }
    else
    {
        return (x*x)%mod;
    }
}
long long modinv(long long x)
{
    return exponent(x,mod-2);
}
long long solve(int n,int r,vector<long long>&fact)
{
    return fact[n]*modinv(fact[r])%mod*modinv(fact[n-r])%mod;
}
    int countGoodArrays(int n, int m, int k) {
      vector<long long>fact(n+1,1);
      for(int i=2;i<n;i++)
      {
        fact[i]=(fact[i-1]*i)%mod;    
      }
      long long res=solve(n-1,k,fact);  
      res=res*m%mod;
      res=res*exponent(m-1,n-k-1)%mod;
      return res;
    }
};