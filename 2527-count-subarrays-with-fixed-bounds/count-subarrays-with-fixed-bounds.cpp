class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
      long long ans=0;
      int mini=-1;
      int maxi=-1;
      int temp=-1;
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]>maxK || nums[i]<minK)
        {
            temp=i;
        }
        if(nums[i]==minK)
        {
            mini=i;
        }
        if(nums[i]==maxK)
        {
            maxi=i;
        }
        int flag=min(mini,maxi)-temp;
        if(flag>0)
        {
   ans+=flag;
        }
      }
      return ans;
    }
};