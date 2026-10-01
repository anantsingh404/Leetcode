class Solution {
    public boolean isValid(String s) {
      Stack<Character>st=new Stack<>();
      for(int i=0;i<s.length();i++)
      {
        char x=s.charAt(i);
        if(st.empty())
        {
            st.add(x);
        }
        else if(x==')' && st.peek()=='(')
        {
            st.pop();
        }
          else if(x==']' && st.peek()=='[')
        {
            st.pop();
        }
          else if(x=='}' && st.peek()=='{')
        {
            st.pop();
        }
        else{
            st.push(x);
        }
      }
     // System.out.println(st.size());
      return st.empty()==true;  
    }
}