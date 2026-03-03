class Solution {
    public char findKthBit(int n, int k) {
        StringBuilder s1 = new StringBuilder("0");  
        while(s1.length()<k) 
        {
            StringBuilder s2=new StringBuilder(s1);
            for(int i=0;i<s2.length();i++)
            {
                if(s2.charAt(i)=='0')
                {
                    s2.setCharAt(i,'1');
                }
                else
                {
                    s2.setCharAt(i,'0');
                }
               
                
            } 
            s2.reverse();
            s1.append("1");
            s1.append(s2);
        }
        return s1.charAt(k-1);
    }
}