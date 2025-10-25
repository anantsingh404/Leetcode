class Solution {
public:
    int totalMoney(int n) {
      int x=n/7;
      int start=1+x;
      int q=n%7;
      int sum=x*28;
      while(x>1)
      {
          sum+=((x-1)*7);
          --x;

      }
      if(n%7)
      {
        while(q--)
        {
            sum+=start++;
        }
      }
      return sum;

    }
};