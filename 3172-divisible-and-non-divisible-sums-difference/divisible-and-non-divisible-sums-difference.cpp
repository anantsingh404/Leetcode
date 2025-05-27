class Solution {
public:
    int differenceOfSums(int n, int m) {
      int sum=((n)*(n+1))/2;  
      int x=0;
      for(int i=1;i<=1000;i++)
      {
        if(m*i<=n)
        {
            x+=m*i;
            sum-=m*i;
        }
      }
      return sum-x;
    }
};