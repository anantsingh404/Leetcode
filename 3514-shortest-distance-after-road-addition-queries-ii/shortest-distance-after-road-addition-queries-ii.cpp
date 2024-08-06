class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
      vector<int>res;
      set<int>st;
      for(int i=0;i<n;i++)
      {
        st.insert(i);
      } 
      for(auto itr:queries)
      {
        int sc=itr[0];
        int ec=itr[1];
        
        auto lb=st.lower_bound(sc+1);
        auto ub=st.lower_bound(ec);
        st.erase(lb,ub);
        res.push_back(st.size()-1);
      } 
      return res;
    }
};