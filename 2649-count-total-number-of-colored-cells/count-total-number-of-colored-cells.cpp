class Solution {
public:
    long long coloredCells(int n) {
     long long ans=0;
       for(int i=1;i<=n;i++)
       {
        if(i==1)
        {
            ans=1;

        }
        else
        {
            ans+=(4*(i-1));
        }
       }
       return ans;
    }
};