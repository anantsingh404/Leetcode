const int INF = 1e9 + 7;
class DSU{
    public:
        vector<int> par;
        vector<int> rank;
        int n;
        DSU(){
            n = 0;
        }
        DSU(int n){
            this -> n = n;
            par = vector<int>(n);
            for(int i = 0; i < n; ++i){
                par[i] = i;
            }
            rank = vector<int>(n, 1);
        }
        int get_par(int u){
            if(par[u] == u){
                return u;
            }
            return par[u] = get_par(par[u]);
        }
        void merge(int u, int v){
            u = get_par(u);
            v = get_par(v);
            if(u == v){
                return;
            }
            if(rank[u] < rank[v]){
                swap(u, v);
            }
            par[v] = u;
            rank[u] += rank[v];
            --n;
        }
        int size(){
            return n;
        }
};


class Solution {
public:
    vector<int> divisors(int n){
        vector<int> res;
        for(int d = 1; d * d <= n; ++d){
            if(n % d){
                continue;
            }
            res.push_back(d);
            if(d * d != n){
                res.push_back(n / d);
            }
        }
        return res;
    }
    int countComponents(vector<int>& nums, int threshold) {
        int num_components = 0;
        sort(nums.begin(),nums.end());
        vector<int> candidate_nodes;
        for(int elem: nums)
        {
            if(elem > threshold){
                ++num_components;
            }
            else{
                candidate_nodes.push_back(elem);
            }
        }
        
        int m = candidate_nodes.size();
        
        vector<int> smallest_multiple(threshold + 1, -1);
        int i = 0;
        for(int elem: candidate_nodes){
            for(int d: divisors(elem)){
                if(smallest_multiple[d] == -1){
                    smallest_multiple[d] = i;
                }
            }
            ++i;
        }
        
        DSU dsu(m);
        
        for(int i = 0; i < m; ++i){
            for(int d: divisors(candidate_nodes[i])){
                if(lcm(candidate_nodes[smallest_multiple[d]], candidate_nodes[i]) <= threshold){
                    dsu.merge(i, smallest_multiple[d]);
                }
            }
        }
        
        num_components += dsu.size();
        return num_components;
    }
};