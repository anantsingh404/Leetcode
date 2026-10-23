class Solution {
    public int sortPermutation(int[] nums) {
       int temp=Integer.MAX_VALUE;
       for(int i=0;i<nums.length;i++){
        if(nums[i]!=i)
        {
            temp=temp&nums[i];
        }
       }
       if(temp==Integer.MAX_VALUE)
       {
        return 0;
       }
       return temp; 
    }
}