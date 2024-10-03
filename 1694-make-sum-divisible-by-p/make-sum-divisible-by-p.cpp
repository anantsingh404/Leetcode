class Solution {
public:
    int minSubarray(vector<int>& arr, long long p) {
        long long n=arr.size();

       
       long long sum=accumulate(arr.begin(),arr.end(),1ll*0);
       if(sum%p==0)
       {
        return 0;
       }
       long long x=sum%p;

       unordered_map<long long,long long>mp;
       long long count=0;
       long long ans=n;
       mp[0]=-1;
       for(long long i=0;i<n;i++)
       {
        count+=arr[i];
       // count%=p;
       
        if(mp.find((count%p-x+p)%p)!=mp.end())
        {
            ans=min(ans,i-mp[(count%p+p-x)%p]);
            
        }
        mp[count%p]=i;
       }
       if(ans>=arr.size())
       {
        return -1;
       }
       return ans;
    }
};