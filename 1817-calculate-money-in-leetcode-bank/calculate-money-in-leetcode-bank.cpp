class Solution {
public:
    int totalMoney(int n) {
      int x=n/7;
      int p=x;
      int sum=x*28;
      --x;
      int i=1;
      while(x>0)
      {
          sum+=(i*7);
          i++;
          --x;

      }
      if(n%7)
      {
        int start=1+p;
        int q=n%7;
        while(q--)
        {sum+=start++;}
      }
      return sum;

    }
};