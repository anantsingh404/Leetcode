class Solution {
    public int findMin(int[] nums) 
    {
       int n=nums.length;
       int mini=0;
       int maxi=n-1;
       int ans=Integer.MAX_VALUE;
       while(mini<=maxi)
       {
        int mid=(mini+maxi)/2;
        if(nums[mid]>=nums[mini] && nums[mid]<=nums[maxi])
        {   ans=Math.min(nums[mini],ans);
            maxi=mid-1;


        }
     
        else if(nums[mid]>=nums[mini] && nums[mid]>=nums[maxi])
        {   
            ans=Math.min(nums[mini],ans);
            ans=Math.min(nums[maxi],ans);
            mini=mid+1;
           
        }
        else if(nums[mid]<=nums[mini] && nums[mid]<=nums[maxi])
        {    ans=Math.min(nums[mid],ans);
            maxi=mid-1;
        }
       } 
       return ans;
    }
}