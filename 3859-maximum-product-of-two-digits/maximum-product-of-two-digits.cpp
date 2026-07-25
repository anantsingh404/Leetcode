class Solution {
public:
    int maxProduct(int n) {
      int maxi1=-1;
      int maxic1=0;  
         int maxi2=-1;
      int maxic2=0;
      
      while(n>0)
      {
        int  mod=n%10;
        if(mod>maxi1)
        {  
             maxi2=maxi1;
            maxic2=maxic1;
            maxi1=n%10;
            maxic1=1;
        }
        else if(mod>maxi2)
        {  
             maxi2=mod;
            maxic2=1;
        }
        else if(mod==maxi1)
        {
          //  maxi1=n%10;
            maxic1+=1;
        }
        n/=10;
      }
      if(maxic1>1)
      {
        return maxi1*maxi1;
      }
      return maxi1*maxi2; 
    }
};