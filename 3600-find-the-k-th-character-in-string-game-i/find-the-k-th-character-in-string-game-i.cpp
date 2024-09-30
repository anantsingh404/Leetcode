class Solution {
public:
    char kthCharacter(int k) {
       string x="a";
        while(x.size()<k)
        {
            string y=x;
            for(int i=0;i<x.size();i++)
            {
                y[i]=y[i]+1;
            }
            x=x+y;
        }
        return x[k-1];
    }
};