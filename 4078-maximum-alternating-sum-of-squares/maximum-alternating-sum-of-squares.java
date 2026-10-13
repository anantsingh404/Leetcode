class Solution {
    public long maxAlternatingSum(int[] nums) {
       long ans=0;
      
       int n=nums.length;
       for(int i=n-1;i>=0;i--)
       {
        if(nums[i]<0)
        {
            nums[i]=nums[i]*-1;
        }
       }
        Arrays.sort(nums);
       for(int i=n-1;i>=0;i--)
       {
          if(i>=(n/2))
          {
            ans+=nums[i]*nums[i];
          }
         
          else
          {
            ans-=nums[i]*nums[i];
          }

       } 
       return ans;
    }
}