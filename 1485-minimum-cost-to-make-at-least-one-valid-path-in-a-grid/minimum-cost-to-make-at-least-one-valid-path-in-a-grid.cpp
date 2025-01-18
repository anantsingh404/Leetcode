class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
    int m = grid[0].size();

    int arr[4] = {0, 0, 1, -1};
    int brr[4] = {1, -1, 0, 0};

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[0][0] = 0;

    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int cost = current.first;
        int x = current.second.first;
        int y = current.second.second;

        if (x == n - 1 && y == m - 1) {
            return cost;
        }

        if (cost > dp[x][y]) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + arr[i];
            int ny = y + brr[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int newCost = cost + (grid[x][y] != i + 1 ? 1 : 0);

                if (newCost < dp[nx][ny]) {
                    dp[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
    }

    return dp[n - 1][m - 1]; 
    }
};