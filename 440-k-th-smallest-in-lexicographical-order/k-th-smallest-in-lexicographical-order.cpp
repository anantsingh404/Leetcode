class Solution {
public:
 long getReqNum(long a,long b,long n){
        long gap=0; 
        while(a <= n){
            gap += min(n+1,b)-a;
            a*=10;
            b*=10;
        }
        return gap;
    }
    long  findKthNumber(int n, int k) {
        long num = 1;
        for(int i=1; i<k;){
            long req = getReqNum(num,num+1,1ll*n);
            if(i+req <= k){
                i+=req;
                num++;
            }else{
                i++;
                num *= 10;
            }
        }
        return num; 
    }
};