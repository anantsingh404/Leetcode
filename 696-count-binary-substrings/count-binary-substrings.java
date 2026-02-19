class Solution {
    public int countBinarySubstrings(String s) {
     Integer n=s.length();
     ArrayList<Integer>ls=new ArrayList<>();
     int i=0;
     while(i<n)
     {
        int j=i;
        while(j<n && s.charAt(j)==s.charAt(i))
        {
            j++;
        }
        ls.add(j-i);
        i=j;
     } 
     Integer ans=0;
     for(int k=0;k<ls.size()-1;k++)
     {
      ans+=Math.min(ls.get(k),ls.get(k+1));
     }  
     return ans;
    }
}