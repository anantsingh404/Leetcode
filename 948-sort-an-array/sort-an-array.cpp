class Solution {
public:
vector<int>partition(vector<int>&nums1,vector<int>&nums2)
{
    vector<int>ans;
    int i=0;
    int j=0;
    while(i<nums1.size() && j<nums2.size())
    {
        if(nums1[i]<=nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
        }
        else
        {
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while(i<nums1.size())
    {
        ans.push_back(nums1[i]);
        i++;
    }
    while(j<nums2.size())
    {
        ans.push_back(nums2[j]);
        j++;
    }
    return ans;
}
vector<int> mergesort(vector<int>&nums,int i,int j)
{
    
    if(i==j)
    {
        return {nums[i]};
    }
    int mid=(i+j)/2;
    vector<int>dp1=mergesort(nums,i,mid);
    vector<int>dp2=mergesort(nums,mid+1,j);
    vector<int>x=partition(dp1,dp2);
    return x;
}
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
      return mergesort(nums,0,n-1); 
    
    }
};