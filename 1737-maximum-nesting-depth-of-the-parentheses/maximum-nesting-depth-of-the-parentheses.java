class Solution {
    public int maxDepth(String s) {
      int ans=0;
      int count=0;
      int n=s.length();
      for(int i=0;i<n;i++){
        char x=s.charAt(i);
        if(x=='(')
        {
            ++count;

        }
         if(x==')')
        {
            --count;

        }
        ans=Math.max(ans,count);
      }
      return ans;  
    }
}