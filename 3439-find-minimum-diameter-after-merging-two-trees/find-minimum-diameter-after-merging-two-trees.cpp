class Solution {
public:
    vector<vector<int>> createGraph(const vector<vector<int>>& edges, int numNodes) {
    vector<vector<int>> graph(numNodes);
    
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        
        // Add edge u -> v
        graph[u].push_back(v);
        // Assuming it's an undirected graph, also add edge v -> u
        graph[v].push_back(u);
    }
    
    return graph;
}

// Helper function for DFS traversal to find the farthest node and its distance
void dfs(int node, const vector<vector<int>>& graph, int parent, int& farthestNode, int& maxDistance, int cd) {
    for (int neighbor : graph[node]) {
        if (neighbor != parent) {
            // Recursively visit neighbors
            dfs(neighbor, graph, node, farthestNode, maxDistance, cd + 1);
        }
    }
    
    // Update farthestNode and maxDistance if current node is farther
    if (maxDistance < cd) {
        farthestNode = node;
        maxDistance = cd;
    }
}

int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    // Create graphs from edge lists using vectors
    vector<vector<int>> graph1 = createGraph(edges1, edges1.size()+1);
    vector<vector<int>> graph2 = createGraph(edges2, edges2.size()+1);
    
    int farthestNode1 = 0;
    int maxDistance1 = 0;
    
    // Find farthest node and its distance in graph1
    dfs(0, graph1, -1, farthestNode1, maxDistance1, 0);
    dfs(farthestNode1, graph1, -1, farthestNode1, maxDistance1, 0);
    int x=0;
    int y=0;
    x=maxDistance1;
    // Adjust maxDistance1 for diameter calculation
    if (maxDistance1 % 2) {
        maxDistance1 = maxDistance1 / 2 + 1;
    } else {
        maxDistance1 = maxDistance1 / 2;
    }
    
    int farthestNode2 = 0;
    int maxDistance2 = 0;
    
    // Find farthest node and its distance in graph2
    dfs(0, graph2, -1, farthestNode2, maxDistance2, 0);
   
    dfs(farthestNode2, graph2, -1, farthestNode2, maxDistance2, 0);
     y=maxDistance2;
    // Adjust maxDistance2 for diameter calculation
    if (maxDistance2 % 2) {
        maxDistance2 = maxDistance2 / 2 + 1;
    } else {
        maxDistance2 = maxDistance2 / 2;
    }
    y=max(x,y);
    // Return the minimum diameter after merge
    return max(maxDistance1 + maxDistance2 + 1,y);
}

};