class Solution {
public:

    bool canRemove(int r1, int c1, int r2, int c2, int i, int j) {
        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;

        if (rows * cols == 1) {
            return false;
        }

        if (rows == 1) {
            return (j == c1 || j == c2);
        }

        if (cols == 1) {
            return (i == r1 || i == r2);
        }

        return true;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<long long> prefRow(n, 0), prefCol(m, 0);

        map<long long, vector<pair<int,int>>> mp;

        int i, j;

        // build prefix row + map
        i = 0;
        while (i < n) {
            long long val = 0;
            j = 0;
            while (j < m) {
                val += grid[i][j];
                mp[grid[i][j]].push_back({i, j});
                j++;
            }
            if (i == 0) {
                prefRow[i] = val;
            } else {
                prefRow[i] = prefRow[i - 1] + val;
            }
            i++;
        }

        // build prefix col
        j = 0;
        while (j < m) {
            long long val = 0;
            i = 0;
            while (i < n) {
                val += grid[i][j];
                i++;
            }
            if (j == 0) {
                prefCol[j] = val;
            } else {
                prefCol[j] = prefCol[j - 1] + val;
            }
            j++;
        }

        long long total = prefRow[n - 1];

        // -------- HORIZONTAL CUT --------
        i = 0;
        while (i < n - 1) {

            long long top = prefRow[i];
            long long bottom = total - top;

            if (top == bottom) {
                return true;
            }

            long long diff = llabs(top - bottom);

            if (mp.find(diff) != mp.end()) {

                if (top > bottom) {
                    for (auto &p : mp[diff]) {
                        int x = p.first;
                        int y = p.second;

                        if (x <= i) {
                            if (canRemove(0, 0, i, m - 1, x, y)) {
                                return true;
                            }
                        }
                    }
                } else {
                    for (auto &p : mp[diff]) {
                        int x = p.first;
                        int y = p.second;

                        if (x > i) {
                            if (canRemove(i + 1, 0, n - 1, m - 1, x, y)) {
                                return true;
                            }
                        }
                    }
                }
            }

            i++;
        }

        // -------- VERTICAL CUT --------
        j = 0;
        while (j < m - 1) {

            long long left = prefCol[j];
            long long right = total - left;

            if (left == right) {
                return true;
            }

            long long diff = llabs(left - right);

            if (mp.find(diff) != mp.end()) {

                if (left > right) {
                    for (auto &p : mp[diff]) {
                        int x = p.first;
                        int y = p.second;

                        if (y <= j) {
                            if (canRemove(0, 0, n - 1, j, x, y)) {
                                return true;
                            }
                        }
                    }
                } else {
                    for (auto &p : mp[diff]) {
                        int x = p.first;
                        int y = p.second;

                        if (y > j) {
                            if (canRemove(0, j + 1, n - 1, m - 1, x, y)) {
                                return true;
                            }
                        }
                    }
                }
            }

            j++;
        }

        return false;
    }
};