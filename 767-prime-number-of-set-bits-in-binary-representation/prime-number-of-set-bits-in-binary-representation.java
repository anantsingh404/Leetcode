class Solution {
    boolean isprime(int num){
        if(num==1)
        {
            return false;
        }
        for(int i=2;i*i<=num;i++)
        {
            if(num%i==0)
            {
                return false;
            }
        }
        return true;
    }
    public int countPrimeSetBits(int left, int right) {
      int ans=0;
      for(int i=left;i<=right;i++)
      {
        int count=0;
        for(int j=0;j<32;j++)
        {
            if(((1<<j)&i)>=1)
            {
                ++count;
            }
        }
        if(isprime(count)==true)
        {   //System.out.println(count);
            ++ans;
        }
      }
      return ans;  
    }
}