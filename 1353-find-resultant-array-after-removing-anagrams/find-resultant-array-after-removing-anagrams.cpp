class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
       int n=words.size();
       
       stack<string>st;
       st.push(words[0]);
       for(int i=1;i<n;i++)
       {
        if(!st.empty())
        {   
            string p=st.top();
            sort(p.begin(),p.end());
            string q=words[i];
            sort(q.begin(),q.end());
            if(p==q)
            {
                continue;
            }
            else
            {
                st.push(words[i]);
            }
        }
        else{
            st.push(words[i]);
        }
       }
       vector<string>s;
       while(!st.empty())
       {
         s.push_back(st.top());
         st.pop();
       }
       reverse(s.begin(),s.end());
       return s;


    }
};