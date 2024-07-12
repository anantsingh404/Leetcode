class Solution {
public:
    int maximumGain(string s, int x, int y) {
      
      stack<char>st;
      string temp;
      int count=0;
      if(x>=y){
      for(int i=0;i<s.size();i++)
      {
       if(st.empty())
       {
        st.push(s[i]);
       }
       else if(st.top()=='a' && s[i]=='b')
       {
        count+=x;
        st.pop();
       }
       else
       {
        st.push(s[i]);
       }
      }
      while(!st.empty())
      {
        temp.push_back(st.top());
        st.pop();
      }
      reverse(temp.begin(),temp.end());
      s=temp;
      for(int i=0;i<s.size();i++)
      {
       if(st.empty())
       {
        st.push(s[i]);
       }
       else if(st.top()=='b' && s[i]=='a')
       {
        count+=y;
        st.pop();
       }
       else
       {
        st.push(s[i]);
       }
      }
      }
      else
      {
          for(int i=0;i<s.size();i++)
      {
       if(st.empty())
       {
        st.push(s[i]);
       }
       else if(st.top()=='b' && s[i]=='a')
       {
        count+=y;
        st.pop();
       }
       else
       {
        st.push(s[i]);
       }
      }
      while(!st.empty())
      {
        temp.push_back(st.top());
        st.pop();
      }
      reverse(temp.begin(),temp.end());
      s=temp;
      for(int i=0;i<s.size();i++)
      {
       if(st.empty())
       {
        st.push(s[i]);
       }
       else if(st.top()=='a' && s[i]=='b')
       {
        count+=x;
        st.pop();
       }
       else
       {
        st.push(s[i]);
       }
      }
      }
      return count;
    }
};