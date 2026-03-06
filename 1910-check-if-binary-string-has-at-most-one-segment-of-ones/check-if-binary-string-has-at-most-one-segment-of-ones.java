class Solution {
    public boolean checkOnesSegment(String s) {
      int count=1;
      int temp=1;
      int n=s.length();
      for(int i=0;i<n;i++)
      {
        char x=s.charAt(i);
        if(x=='1' && temp==0)
        {
           ++count;
        }
        else if(x=='0' && temp==1)
        {
            temp=0;
        }
      }
      return count<=1;

    }
}