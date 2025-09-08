class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
    vector<int>ans;
    for(int i=1;i<=n/2;i++)
    {
        int j=n-i;
        int p=i;
        int q=j;
        bool temp=true;
        while(p>0)
        {
            if(p%10==0)
            {
                temp=false;
                break;
            }
            p/=10;
        }
         while(q>0)
        {
            if(q%10==0)
            {
                temp=false;
                break;
            }
            q/=10;
        }
        if(temp)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
    }
};