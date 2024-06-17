class Solution {
public:
    bool judgeSquareSum(int c) {
      long long ans=0;
      if(c==0)
      {
        return true;
      }
      int x=pow(2,16);
      for(int i=0;i<=x;i++)
      {
        ans+=pow(i,2);
        long long flag=c-ans;
        if(flag<=0)
        {
            return false;
        }
        long long temp=sqrt(flag);
        if(temp*temp==flag)
        {
            return true;
        }
        ans=0;
      }  
      return false;
    }
};