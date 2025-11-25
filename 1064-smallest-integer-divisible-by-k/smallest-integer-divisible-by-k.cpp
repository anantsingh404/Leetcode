class Solution {
public:
    int smallestRepunitDivByK(int k) {
     if(k%2==0)
     {
        return -1;
     }
     long long mod=0;
     for(int i=1;i<=1e5;i++)
     {
       mod=(mod*10+1)%k;
       if(mod%k==0)
       {
        return i;
       } 
        
     }
     return -1;
     

    }
};