class Solution {
public:
const int mod=1e9+7;
    long long solve(int n,long long x)
    {
        if(x==0)
        {
            return 1;
        }
        long long p=solve(n,x/2);
        if(x%2)
        {
            return (p*p*n)%mod;
        }
        return (p*p)%mod;
    }
    int countGoodNumbers(long long n) {
      long long odd=0;
      long long even=0;
      if(n%2)
      { 
        odd=n/2;
        even=odd+1;
      }
      else
      {
        odd=(n/2);
        even=n/2;
      }
      long long x=solve(4,odd);
      long long y=solve(5,even);
      return (int)((x*y)%mod);
    }
};