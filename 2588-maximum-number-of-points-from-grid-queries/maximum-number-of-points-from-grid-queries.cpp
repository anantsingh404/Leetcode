class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> vp;
    for (int i = 0; i < queries.size(); i++) {
        vp.push_back({queries[i], i});
    }
    sort(vp.begin(), vp.end());

    vector<int> ans(queries.size(), 0);
    vector<vector<int>> vis(n, vector<int>(m, 0));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({grid[0][0], {0, 0}}); 
    vis[0][0] = 1;

    int arr[4] = {0, 0, -1, 1};
    int brr[4] = {-1, 1, 0, 0};

    int count = 0;
    int flag = 0;

    for (auto [val, idx] : vp) {
        while (!pq.empty() && pq.top().first < val) {
            auto [gval, coord] = pq.top();
            pq.pop();
            int x = coord.first, y = coord.second;
            count++;
            
            for (int k = 0; k < 4; k++) {
                int xx = x + arr[k], yy = y + brr[k];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy]) {
                    vis[xx][yy] = 1;
                    pq.push({grid[xx][yy], {xx, yy}});
                }
            }
        }
        ans[idx] = count;
    }
    return ans; 
    }
};