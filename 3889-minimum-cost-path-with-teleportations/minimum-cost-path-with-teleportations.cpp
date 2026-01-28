class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;

        int dist[81][81][11];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                for(int t=0;t<=k;t++)
                    dist[i][j][t] = INF;

        vector<array<int,3>> cells;
        cells.reserve(m*n);

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cells.push_back({grid[i][j], i, j});

        sort(cells.begin(), cells.end());

        vector<int> ptr(k+1, 0);

        using T = array<int,4>; 
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][0][0] = 0;
        pq.push({0,0,0,0});

        int dr[2] = {1,0};
        int dc[2] = {0,1};

        while(!pq.empty()) {
            auto [cost,r,c,used] = pq.top();
            pq.pop();

            if(cost != dist[r][c][used]) continue;

            if(r==m-1 && c==n-1)
                return cost;

            for(int d=0; d<2; d++){
                int nr=r+dr[d], nc=c+dc[d];
                if(nr<m && nc<n){
                    int newCost = cost + grid[nr][nc];
                    if(newCost < dist[nr][nc][used]){
                        dist[nr][nc][used] = newCost;
                        pq.push({newCost,nr,nc,used});
                    }
                }
            }

            if(used < k){
                int val = grid[r][c];

                while(ptr[used] < cells.size() &&
                      cells[ptr[used]][0] <= val){

                    auto &cell = cells[ptr[used]];
                    int nr = cell[1], nc = cell[2];
                    ptr[used]++;

                    if(cost < dist[nr][nc][used+1]){
                        dist[nr][nc][used+1] = cost;
                        pq.push({cost,nr,nc,used+1});
                    }
                }
            }
        }

        return -1;
    }
};