class Solution {
public:
pair<int, int> bfs(int start, const vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    int farthestNode = start;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (dist[neighbor] == -1) { // Not visited
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
                farthestNode = neighbor;
            }
        }
    }

    return {farthestNode, dist[farthestNode]};
}

// Function to calculate the diameter of a graph
int calculateDiameter(const vector<vector<int>> &graph) {
    // Step 1: Find the farthest node from any starting point (e.g., node 0)
    pair<int, int> firstBFS = bfs(0, graph);

    // Step 2: Perform BFS again from the farthest node found
    pair<int, int> secondBFS = bfs(firstBFS.first, graph);

    // The distance in the second BFS is the diameter
    return secondBFS.second;
}
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1=edges1.size()+1;
          vector<vector<int>> graph1(n1);

    for (auto &edge : edges1) {
        graph1[edge[0]].push_back(edge[1]);
        graph1[edge[1]].push_back(edge[0]);
    }

         int n2=edges2.size()+1;
  
    
    vector<vector<int>> graph2(n2);

    for (auto &edge : edges2) {
        graph2[edge[0]].push_back(edge[1]);
        graph2[edge[1]].push_back(edge[0]);
        
    }
    int diameter1 = calculateDiameter(graph1);
    int diameter2 = calculateDiameter(graph2);
    int x=max(diameter1,diameter2);
    return max(x,1+diameter1/2+diameter1%2+diameter2/2+diameter2%2);
    }
};