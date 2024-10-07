class Solution {
public:
    int minLength(string s) {
      stack<char>st;
      int i=0;
      while(i<s.size())
      {
        if(st.empty())
        {
            st.push(s[i]);
        }
        else if(s[i]=='B'  && st.top()=='A')
        {
            st.pop();
        }
         else if(s[i]=='D'  && st.top()=='C')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
        i++;
      }
      return st.size();  
    }
};