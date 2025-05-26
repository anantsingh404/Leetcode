class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n=nums.size();
       int mini=0;
       int maxi=n-1;
       while(mini<=maxi)
       {
        int mid=(mini+maxi)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(nums[mid]<target)
        {
            if(nums[mini]>nums[mid])
            {
                if(nums[mini]>target)
                {
                    mini=mid+1;
                }
                else if(nums[mini]<=target)
                {
                    maxi=mid-1;
                }
            }
            else
            {
                mini=mid+1;
            }
        }
        else
        {  
            if(nums[mid]>nums[maxi] && nums[maxi]>=target)
            {
                mini=mid+1;
            }
            else{
           maxi=mid-1;
            }
        }
       } 
       return -1;
    }
};