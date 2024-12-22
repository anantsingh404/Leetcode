class Solution {
public:
    int minCost(const vector<int> & chunks, int max_len) { // minimum cost with each identical substring's length <= max_len
        int cost = 0;
        for (const auto & x : chunks) {
            cost += x / (max_len + 1);
        }
        return cost;
    }

    int minLength(string s, int numOps) {
        int n = s.size();
        int cost = 0;
        // check if it can be 0101... or 1010... ( `max_len = 1` )
        for (int i = 0 ; i < n ; ++i) {
            if (s[i] != i % 2 + '0') ++cost;
        }
        if (cost <= numOps || n - cost <= numOps) return 1;

        // break into chunks (identical substrings)
        // Example: "00011010011" -> {3, 2, 1, 1, 2, 2}
        vector<int> chunks;
        char c = s[0];
        int start = 0;
        for (int i = 0 ; i < n ; ++i) {
            if (s[i] != c) {
                chunks.push_back(i - start);
                c = s[i];
                start = i;
            }
        }
        chunks.push_back(n - start);
        
        if (numOps == 0) return *max_element(chunks.begin(), chunks.end());
        
        // binary search
        int lb = 1, rb = n;
        while (rb - lb > 1) {
            int mid = (rb + lb) / 2;
            if (minCost(chunks, mid) <= numOps) rb = mid;
            else lb = mid;
        }
        return rb;
    }
};