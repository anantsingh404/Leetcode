class Solution {
    int k;
   void solve(int n, StringBuilder st,ArrayList<String> ls)
   { 
    if(ls.size()==k)
   {
    return ;
   }
    if(n==0)
    {
        ls.add(st.toString());
        return;
    }
    if(st.length()==0)
    {
        st.append('a');
        solve(n-1,st,ls);
        st.deleteCharAt(st.length()-1);
         st.append('b');
        solve(n-1,st,ls);
        st.deleteCharAt(st.length()-1);
         st.append('c');
        solve(n-1,st,ls);
        st.deleteCharAt(st.length()-1);
    }
    else
    {
        char x=st.charAt(st.length()-1);
        if(x=='a')
        {
             st.append('b');
        solve(n-1,st,ls);
        st.deleteCharAt(st.length()-1);
         st.append('c');
        solve(n-1,st,ls);
        st.deleteCharAt(st.length()-1);
        }
          if(x=='b')
        {
             st.append('a');
        solve(n-1,st,ls);
        st.deleteCharAt(st.length()-1);
         st.append('c');
        solve(n-1,st,ls);
        st.deleteCharAt(st.length()-1);
        }
          if(x=='c')
        {
             st.append('a');
        solve(n-1,st,ls);
        st.deleteCharAt(st.length()-1);
         st.append('b');
        solve(n-1,st,ls);
        st.deleteCharAt(st.length()-1);
        }
    }
   }
    public String getHappyString(int n, int kk) {
        k=kk;
        ArrayList<String>ls=new ArrayList<>();
        StringBuilder st=new StringBuilder();
        solve(n,st,ls); 
        if(ls.size()<k)
        {
            return "";
        }
        String res=ls.get(k-1);
        return res;
    }
}