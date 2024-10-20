class Solution {
public:
    bool parseBoolExpr(string exp) {
      stack<char>st;
      for(int i=0;i<exp.size();i++)
      { if(exp[i]==',')
      {
        continue;
      }
        if(st.empty() || exp[i]!=')')
        {
            st.push(exp[i]);
        }
        else
        {
            int countf=0;
            int countt=0;
            while(st.top()!='(')
            {
                if(st.top()=='f')
                {
                    ++countf;
                }
                else
                {
                    ++countt;
                }
                st.pop();
            }
            st.pop();
            char x='t';
            if(st.top()=='!' && countf)
            {
                x='t';
            }
             if(st.top()=='!' && countt>0)
            {
                x='f';
            }
            if(st.top()=='|' && countt==0)
            {
                x='f';
            }
             if(st.top()=='&' && countf)
            {
                x='f';
            }
            st.pop();
            cout<<x<<endl;
            st.push(x);
        }

      }
      if(st.top()=='f')
      {
        return false;
      }
      return true;

    }
};