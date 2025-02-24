class Solution {
public:
     int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> parent(n, -1);
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    parent[neighbor] = node;
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        vector<int> bobTime(n, -1);
        int time = 0, curr = bob;
        while (curr != -1) {
            bobTime[curr] = time++;
            curr = parent[curr];
        }
        int maxProfit = INT_MIN;
        function<void(int, int, int)> dfs = [&](int node, int time, int profit) {
            if (bobTime[node] != -1) {
                if (time < bobTime[node]) profit += amount[node];
                else if (time == bobTime[node]) profit += amount[node] / 2;
            } else profit += amount[node];
            bool isLeaf = true;
            for (int neighbor : adj[node]) {
                if (neighbor != parent[node]) {
                    isLeaf = false;
                    dfs(neighbor, time + 1, profit);
                }
            }
            if (isLeaf) maxProfit = max(maxProfit, profit);
        };
        dfs(0, 0, 0);
        return maxProfit;
    }
};