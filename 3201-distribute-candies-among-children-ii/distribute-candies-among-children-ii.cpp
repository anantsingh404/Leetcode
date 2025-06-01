class Solution {
public:
    long long distributeCandies(int n, int limit) {
      if(n>limit*3)
      {
        return 0;
      }
      long long ans=0;
      for(int i=0;i<=limit;i++)
      {
        int x=n-i;
        if(x<0)
        {
            continue;
        }
        else if(x==0)
        {
            ++ans;
        }
        else if(x<=limit)
        {
            ans+=(x+1);
        }
        else if(x<=2*limit)
        {
            long long p=x-limit;
            ans+=(limit-p+1);
        }
      }
      return ans;

    }
};