class Solution {
    boolean Check(StringBuilder s)
    {
        Stack<Character>st=new Stack<>();
        int n=s.length();
        for(int i=0;i<n;i++)
        {   char x=s.charAt(i);
            if(st.empty())
            {
              st.push(x);
            }
            else if(st.peek()=='(' && x==')')
            {
                st.pop();
            }
            else
            {
                st.push(x);
            }
        }
        return st.empty()==true;
    }
    void solve(int n,StringBuilder temp,List<String>ls)
    {
        if(n==0)
        {
            if(Check(temp))
            {
                ls.add(temp.toString());
            }
            return;
        }
        temp.append(')');
        solve(n-1,temp,ls);
        temp.deleteCharAt(temp.length()-1);
          temp.append('(');
        solve(n-1,temp,ls);
        temp.deleteCharAt(temp.length()-1);
    }
    public List<String> generateParenthesis(int n) {
      List<String>ls=new ArrayList<>();
      StringBuilder temp=new StringBuilder();
      solve(2*n,temp,ls);  
      return ls;
    }
}