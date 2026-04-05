class Solution {
    public boolean judgeCircle(String s) {
     int x=0;
     int y=0;
     for(int i=0;i<s.length();i++)
     {
        if(s.charAt(i)=='L')
        {
            --x;
        }
        else if(s.charAt(i)=='R')
        {
            ++x;
        }
        else if(s.charAt(i)=='U')
        {
            --y;
        }
        else if(s.charAt(i)=='D')
        {
            ++y;
        }
     } 
     return x==0 && y==0;  
    }
}