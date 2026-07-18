class Solution {
    int gcd(int a,int b)
    {
        if(a==0)
        {
            return b;
        }
        if(b==0)
        {
            return a;
        }
        if(a>b)
        {
            return gcd(a%b,b);
        }
        return gcd(a,b%a);
    }
    public int findGCD(int[] nums) {
      int small=1000000;
      int large=0;
      for(int i=0;i<nums.length;i++)
      {
        if(small>nums[i])
        {
            small=nums[i];
        }
        if(large<nums[i]){
            large=nums[i];
        }
      }
      return gcd(small,large);
    }
}