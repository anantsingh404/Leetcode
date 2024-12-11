class Solution {
public:
int n;
int bs(int num,int mini,int maxi,int k,vector<int>&nums)
{  int x=mini;
int temo=x;
    while(mini<=maxi)
    {
        int mid=(maxi+mini)/2;
        if(nums[mid]-num<=2*k)
        {
            x=mid;
            mini=mid+1;
        }
        else
        {
            maxi=mid-1;
        }
    }
    return x-temo+1;
}
    int maximumBeauty(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      int ans=1;
      n=nums.size();
      for(int i=0;i<n-1;i++) 
      {
         int x=bs(nums[i],i,n-1,k,nums);
         ans=max(ans,x);
      } 
      return ans;
    }
};