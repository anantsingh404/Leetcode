class Solution {
public:
    bool check(long long mid,vector<int>&wt,long long height)
    {
        long long sum=0;
        for(int i=0;i<wt.size();i++)
        {
            long long x=(2*mid)/wt[i];
            long long y=(-1+sqrt(1+4*x))/2;
            if(y>0)
            {
                sum+=y;
            }
        }
        return sum>=height;
    }
    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        long long ans=1e18;
        long long mini=1;
        long long maxi=1e18;
        sort(wt.begin(),wt.end());
        while(mini<=maxi)
        {
            long long mid=(maxi+mini)/2;
            if(check(mid,wt,mh))
            {
                ans=mid;
                maxi=mid-1;
            }
            else
            {
            mini=mid+1;
            }
        }
        return ans;
    }
};