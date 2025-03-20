class Solution {
public:
    class DSU {
        public:

        int n;
        vector<int> parent, rank, bitAnd;
        DSU(int _n) {
            n = _n;
            int maxAnd = pow(2, 30) - 1; // 11111..1111
            parent.resize(n);
            bitAnd.resize(n, maxAnd);
            rank.resize(n, 1); // all components rank 1 initialy
            for (int i = 0; i < n; i++) {
                parent[i] = i; // each is its own parent intiially
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // path compression
            }
            return parent[x];
        }

        // while combining edges, add the bitwise AND of edge to component that becomes parent
        void combine(int x, int y, int w) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY) {
                bitAnd[rootX] &= w; // add bitwise AND of edge to component
                return;
            }
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                bitAnd[rootX] &= bitAnd[rootY];
                bitAnd[rootX] &= w;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                bitAnd[rootY] &= bitAnd[rootX];
                bitAnd[rootY] &= w;
            } else { // if equal rank, increase rank of the one with more elements
                parent[rootY] = rootX;
                rank[rootX]++;
                bitAnd[rootX] &= bitAnd[rootY];
                bitAnd[rootX] &= w;
            }
        }

        int getANDofComponent(int root) {
            return bitAnd[root];
        }

    };

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ans;
        DSU dsu = DSU(n);

        for (auto &edge : edges) {
            int ui = edge[0], vi = edge[1], wi = edge[2];
            dsu.combine(ui, vi, wi);
        }

        for (auto &q: query) {
            int ui = q[0], vi = q[1];
            int rootU = dsu.find(ui), rootV = dsu.find(vi);
            if (rootU == rootV) {
                ans.push_back(dsu.getANDofComponent(rootU));
            } else { // diff components, no path exists
                ans.push_back(-1);
            }
        }

        return ans;
    }
};