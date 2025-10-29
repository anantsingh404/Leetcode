class Solution {
public:
    int smallestNumber(int n) {
        int ans=2;
      while(1)
      {
          if(ans>n)
          {
            return ans-1;
          }
          ans*=2;
      }
      return ans;  
    }
};