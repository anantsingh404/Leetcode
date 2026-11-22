class Solution {
    public boolean checkString(String s) {
      int bexist=0;
      for(int i=0;i<s.length();i++)
      {
        if(s.charAt(i)=='b')
        {
            bexist=1;
        }if(s.charAt(i)=='a' && bexist==1)
        {
            return false;
        }
      } 
      return true; 
    }
}