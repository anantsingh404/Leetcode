class Solution {
public:
    int ans=0;
     void solve(int idx,string &s,set<string>&st)
     {
        if(idx==s.size())
        {
            ans=max(ans,(int)(st.size()));
            return ;
        }
        string temp;
        for(int i=idx;i<s.size();i++)
        {
temp.push_back(s[i]);
if(st.find(temp)==st.end())
{
    st.insert(temp);
    solve(i+1,s,st);
    st.erase(temp);
}
        }
        return ;
     }
    int maxUniqueSplit(string s) {
        set<string>st;
     solve(0,s,st);
     return ans;   
    }
};