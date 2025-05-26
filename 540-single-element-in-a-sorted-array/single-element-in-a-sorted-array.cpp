class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2])
        {
            return nums[n-1];
        }
        if(nums[0]!=nums[1])
        {
            return nums[0];
        }
       int mini=1;
       int  maxi=n-2;
       while(mini<=maxi)
       {
        int mid=(maxi+mini)/2;
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
        {
            return nums[mid];
        }
        else if(nums[mid]==nums[mid-1] && mid%2==0)
        {
            maxi=mid-1;
        }
        else if( nums[mid]==nums[mid-1] && mid%2==1)
        {
            mini=mid+1;
        }
        else if(nums[mid]==nums[mid+1] && mid%2==1)
        {
            maxi=mid-1;
        }
        else if(nums[mid]==nums[mid+1] && mid%2==0)
        {
            mini=mid+1;
        }
       // cout<<mini<<' '<<maxi<<endl;
       }
       return -1;

    }
};