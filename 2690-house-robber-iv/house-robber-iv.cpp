class Solution {
public:
long long check(long long mid,vector<int>&nums,int k)
{
    long long sum=0;
    int count=0;
    int maxi=0;
    int i=0;
    int n=nums.size();
    while(i<n)
    {
        if(nums[i]<=mid)
        {
            
            maxi=max(maxi,nums[i]);
            i+=2;
            ++count;
        }
        
        else
        {
            i++;
        }
         if(count==k)
        {
            break;
        }
    }
    if(count>=k)
    {
        return maxi;
    }
    return -1;
}
    int minCapability(vector<int>& nums, int k) {
      int n=nums.size();
      long long mini=*min_element(nums.begin(),nums.end());
      long long maxi=*max_element(nums.begin(),nums.end());
      long long ans=INT_MAX;
      while(mini<=maxi)
      {
        long long mid=(mini+maxi)/2;
        int x=check(mid,nums,k);
        if(x!=-1)
        {
            ans=x;
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