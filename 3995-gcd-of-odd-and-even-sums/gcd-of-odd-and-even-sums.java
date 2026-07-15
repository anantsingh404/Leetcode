class Solution {
   int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

    public int gcdOfOddEvenSums(int n) {
        int sum=(n*(n+1))/2;
        int even=0;
        int odd=0;
        int m=n;
         for(int i=1;m>0;i+=2)
         {
               
               odd+=i;m--;
            
         }
            for(int i=2;n>0;i+=2)
         {
               
               even+=i;n--;
            
         }
         
         return gcd(even,odd);
    }
}