class Solution {
public:
    int numWaterBottles(int nb, int ne) {
       int count=nb;
      while(nb>=ne)
      {
        int x=nb/ne;
        count+=x;
        nb=nb-x*ne;
        nb+=x;
      }  
      return count; 
    }
};