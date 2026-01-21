class Solution {
public:
int bs(int num)
{
int mini=1;
int maxi=1e9;
int ans=-1;
while(mini<=maxi)
{
    int mid=(maxi+mini)/2;
    if((mid|(mid+1))==num)
    {
        ans=mid;
        maxi=mid-1;
    }
    else if((mid|(mid+1))>num)
    {
      maxi=mid-1;
    }
    else
    {
        mini=mid+1;
    }

}
return ans;
}
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
      for(int i=0;i<n;i++)
      { bool ava=false;
        int flag=INT_MAX;
        int anss=INT_MAX;
       for(int j=0;j<=31;j++)
       { 
        
        if(((nums[i]>>j)&1)==1)
        {
            flag=(nums[i]&(~(1<<j)));
            if(flag<0)
            {
                continue;
            }
            if((flag|(flag+1))==nums[i])
            {
           if(flag<anss)
           {
            anss=flag;
            ava=true;
           }
            }
        }
       }
       if(ava==true)
       {
        ans.push_back(anss);
       }
       else
       {
        ans.push_back(-1);
       }
      }
      return ans;
    }
    
};