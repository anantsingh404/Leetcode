class Solution {
public:
    int smallestNumber(int n) {
      int i=1;
      int j=0;
      while(i<n)
      {
        i=i|(1<<j);
        j++;
      } 
      return i; 
    }
};