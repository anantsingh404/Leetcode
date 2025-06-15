class Solution {
public:
    int minMoves(vector<string>& matrix) {
          int m = matrix.size(), n = matrix[0].size();
    const int INF = INT_MAX;
    vector<vector<int>> dist(m, vector<int>(n, INF));
    vector<bool> used(26, false);

    unordered_map<char, vector<pair<int,int>>> portals;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (isupper(matrix[i][j]))
                portals[matrix[i][j]].push_back({i, j});

    deque<pair<int,int>> dq;
    dist[0][0] = 0;
    dq.emplace_back(0, 0);

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (!dq.empty()) {
        auto [x, y] = dq.front();
        int d = dist[x][y];
        dq.pop_front();
        if (x == m - 1 && y == n - 1) return d;

        // Teleportation (cost 0)
        char c = matrix[x][y];
        if (isupper(c) && !used[c - 'A']) {
            used[c - 'A'] = true;
            for (auto [tx, ty] : portals[c]) {
                if (dist[tx][ty] > d) {
                    dist[tx][ty] = d;
                    dq.emplace_front(tx, ty);
                }
            }
        }

        // Adjacent moves (cost 1)
        for (auto &dir : dirs) {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] != '#') {
                if (dist[nx][ny] > d + 1) {
                    dist[nx][ny] = d + 1;
                    dq.emplace_back(nx, ny);
                }
            }
        }
    }

    return -1;
    }
};