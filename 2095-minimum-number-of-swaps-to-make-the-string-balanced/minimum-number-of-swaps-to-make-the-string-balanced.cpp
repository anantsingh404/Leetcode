class Solution {
public:
    int minSwaps(string s) {
       stack<char>st;
       int n=s.size();
       int i=0;
       while(i<s.size())
       {
        if(st.empty())
        {
            st.push(s[i]);
        }
        else if(st.top()=='[' && s[i]==']')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
        i++;
       } 
       if(st.size()==0)
       {
        return 0;
       }
       int x=st.size()/4;
       if(st.size()%4)
       {
        ++x;
       }
       return x;
    }
};