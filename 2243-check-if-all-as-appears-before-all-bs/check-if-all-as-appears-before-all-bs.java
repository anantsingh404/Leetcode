class Solution {
    public boolean checkString(String s) {
      int bexist=0;
      int n=s.length();
      for(int i=0;i<s.length();i++)
      { char x=s.charAt(i);
        if(x=='b')
        {
            bexist=1;
        }
        else if(x=='a' && bexist==1)
        {
            return false;
        }
      } 
      return true; 
    }
}