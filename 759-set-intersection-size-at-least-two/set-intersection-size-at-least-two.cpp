class Solution {
public:
   static bool cmp(vector<int>&a,vector<int>&b)
   {
    if(a[1]==b[1])
    {
        return a[0]>=b[0];
    }
    return a[1]<b[1];
   }
    int intersectionSizeTwo(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end(),cmp);
        int n=inter.size();
        int b=inter[n-1][1];
        int a=inter[n-1][1]-1;
        int ans=0;
        int s1=-1,s2=-1;
        for(auto itr:inter)
        {
            int x=itr[0];
            int y=itr[1];
            if(s1>=x && s2<=y)
            {
                continue;
            }
            if(s2<=y && s2>=x)
            {
                ans+=1;
                s1=s2;
                s2=y;
            }
            else
            {
                ans+=2;
                s1=y-1;
                s2=y;
            }
        }
        
return ans;
    }
};