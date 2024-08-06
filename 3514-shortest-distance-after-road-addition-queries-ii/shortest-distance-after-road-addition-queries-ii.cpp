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
        
        // Find the iterator to the first element greater than sc
        auto lb = st.lower_bound(sc + 1);
        
        // Remove elements from lb to the one just before ec
        while (lb != st.end() && *lb < ec) {
            auto x = lb++;
            st.erase(x);
        }
        
        // Add the result
        res.push_back(st.size() - 1);
    }
    
    return res;
}

int main() {
    // Example usage
    vector<vector<int>> queries = {{0, 2}, {1, 3}, {2, 4}};
    vector<int> result = shortestDistanceAfterQueries(5, queries);
    
    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;
    
    return 0;
}

    
};