class Solution {
public:


vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<int> res;
    set<int> st;
    
    // Initialize the set with all positions from 0 to n-1
    for (int i = 0; i < n; i++) {
        st.insert(i);
    }
    
    for (const auto& itr : queries) {
        int sc = itr[0];
        int ec = itr[1];
        auto lb = st.lower_bound(sc + 1);
        while (lb != st.end() && *lb < ec) {
            auto x = lb++;
            st.erase(x);
        }
        res.push_back(st.size() - 1);
    }
    
    return res;
}
};

