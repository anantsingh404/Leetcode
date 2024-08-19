class Solution {
public:
    int kSimilarity(string s1, string s2) {
       queue<pair<string,int>>q;
       set<string>st;
       q.push({s1,0});
       st.insert(s1);
       while(!q.empty())
       {
        auto x=q.front();
        string temp=x.first;
        q.pop();
        if(x.first==s2)
        {
            return x.second;
        }
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]!=s2[i])
            {
              for(int j=i+1;j<temp.size();j++)
              {
                if(temp[j]==s2[i] && temp[j]!=s2[j])
                {
                    swap(temp[i],temp[j]);
                    if(!st.count(temp))
                    {
                        st.insert(temp);
                        q.push({temp,x.second+1});
                    }
                    swap(temp[i],temp[j]);
                }
              } 
              break;   
            }
        }
       }
       return -1;  
    }
};