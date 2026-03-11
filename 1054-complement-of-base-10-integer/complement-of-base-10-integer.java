class Solution {
    public int bitwiseComplement(int n) {
        int last=-1;
         if(n==0)
     {
        return 1;
     }
     for(int i=31;i>=0;i--)
     {
      if(last==-1 && (n&(1<<i))>=1)
      {
        last=1;
        n=n^(1<<i);
        
      }
      else if(last==1)
      {
         n=n^(1<<i);
      }
     }
    
     return n;   
    }
}