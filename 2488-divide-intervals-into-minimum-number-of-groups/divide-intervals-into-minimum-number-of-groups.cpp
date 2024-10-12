class Solution {
public:
    int minGroups(vector<vector<int>>& intersect) {
        multiset<pair<int,int>>st;
        for(int i=0;i<intersect.size();i++)
        {
            st.insert(make_pair(intersect[i][0],intersect[i][1]));
        } 
        int ans=0;
       while(!st.empty())
       {
        auto itr=*st.begin();
        st.erase(st.begin());
        int cur=itr.second;
        while(true)
        {
            auto mx=st.upper_bound(make_pair(cur,INT_MAX));
            if(mx==st.end())
            {
                break;
            }
            cur=mx->second;
            st.erase(mx);
        }
        ++ans;
       }
       return ans;
    }
};