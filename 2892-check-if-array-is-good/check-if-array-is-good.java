class Solution {
    public boolean isGood(int[] nums) {
     int n=nums.length;
     for(int i=0;i<n;i++)
     {
        int x=nums[i]%(n+2);
        if(x<1 || x>=n)
        {
            return false;
        }
        if(x>0)
        {
        nums[x-1]+=(n+2);
        }
     } 
      for(int i=0;i<n;i++)
     {
        int x=nums[i]/(n+2);
        if(x!=1 && i<n-2)
        {
             return false;
        }
        if(i==n-2)
        {
            if(x!=2)
            {
                return false;
            }
        }
        if(i==n-1)
        {
            if(x!=0)
            {
                return false;
            }
        }
     } 
     return true; 

    }
}