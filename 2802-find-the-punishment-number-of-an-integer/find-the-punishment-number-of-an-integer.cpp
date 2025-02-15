class Solution {
public:
bool check(int di,int total,int sum)
{    if(total==0 && sum==di)
{
    return true;
}
if(total==0)
{
    return false;
}
    bool ans=true;
    for(int i=10;i<=1e6;i*=10)
    {
        if(check(di,total/i,sum+total%i))
        {
            return true;
        }
    }
    return false;
}
    int punishmentNumber(int n) {
     int sum=0;
     for(int i=1;i<=n;i++)
     {
       if(check(i,pow(i,2),0))
       {
        sum+=pow(i,2);
       }
     }
     return sum;   
    }
};