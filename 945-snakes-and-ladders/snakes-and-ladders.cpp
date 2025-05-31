class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
    vector<int> dp(n * n + 1, INT_MAX);
    dp[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});

    auto getCoord = [&](int s) -> pair<int, int> {
        int r = n - 1 - (s - 1) / n;
        int c = (s - 1) % n;
        if (((n - 1 - r) % 2) == 1) c = n - 1 - c;
        return {r, c};
    };

    while (!pq.empty()) {
        auto [x, y] = pq.top();
        pq.pop();
        if (y == n * n) break;

        for (int i = 1; i <= 6; i++) {
            int p = y + i;
            if (p > n * n) continue;

            auto [xc, yc] = getCoord(p);
            int q = board[xc][yc] != -1 ? board[xc][yc] : p;

            if (dp[q] > x + 1) {
                dp[q] = x + 1;
                pq.push({x + 1, q});
            }
        }
    }

    return dp[n * n] == INT_MAX ? -1 : dp[n * n]; 
    }
};