class Solution {
    public boolean hasAllCodes(String s, int k) {
      HashSet<String>st=new HashSet<>();
      int n=s.length();
      
      for(int i=0;i<=n-k;i++)
      {
        String x=s.substring(i,i+k);
        st.add(x);
      } 
      int x=1;
      while(k>0)
      {
        x*=2;
        --k;
      }
      int y=st.size();
      return x==y; 
    }
}