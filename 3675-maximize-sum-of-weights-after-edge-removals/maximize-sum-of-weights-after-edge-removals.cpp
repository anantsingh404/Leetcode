class Solution {
public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
          int n = edges.size() + 1;
        
        vector<vector<pair<int,int>>>adj(n);
        
        for(auto &i : edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        vector<vector<long long>>dp(n, vector<long long>(2, -1ll));
        
        auto f = [&](int i, int j, int parent, auto &&self) -> long long {
            if(dp[i][j] != -1) return dp[i][j];
                        
            int opsToDo = max(0, int(adj[i].size()) - k - j);
            long long answer = 0;
                        
            vector<pair<long long, long long>>children;
            
            for(auto &[neigh, weight] : adj[i]) {
                if(neigh != parent) {
                    long long take = self(neigh, 0, i, self) + weight;
                    long long notTake = self(neigh, 1, i, self);
                    children.push_back({take, notTake});
                }   
            }
            
            sort(children.begin(), children.end(), [&](auto &l, auto &r) {
                return l.first - l.second < r.first - r.second; 
            });
                        
            for(int i = 0; i < children.size(); i++) {
                if(i < opsToDo) answer += children[i].second;
                else answer += max(children[i].first, children[i].second);
            }            
            
            return dp[i][j] = answer;
        };
        
        return f(0, 0, 0, f); 
    }
};