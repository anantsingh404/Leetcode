class Solution {
public:
    int smallestNumber(int n, int t) {
     int x=n;
     while(x)
         {
             string xx=to_string(x);
             int m=xx.size();
             int p=1;
             for(int i=0;i<m;i++)
                 {
                    p=p*(xx[i]-'0'); 
                 }
             if(p%t==0)
             {
                 return x;
             }
             ++x;
         }
return x;
       
       
        
    }
};