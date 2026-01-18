class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int side = 2; i + side <= n && j + side <= m; side++) {

                    set<long long> st;

                    // rows
                    for (int r = i; r < i + side; r++) {
                        long long sum = 0;
                        for (int c = j; c < j + side; c++) {
                            sum += grid[r][c];
                        }
                        st.insert(sum);
                    }

                    // columns
                    for (int c = j; c < j + side; c++) {
                        long long sum = 0;
                        for (int r = i; r < i + side; r++) {
                            sum += grid[r][c];
                        }
                        st.insert(sum);
                    }

                    // main diagonal
                    long long d1 = 0;
                    for (int k = 0; k < side; k++) {
                        d1 += grid[i + k][j + k];
                    }
                    st.insert(d1);

                    // anti-diagonal
                    long long d2 = 0;
                    for (int k = 0; k < side; k++) {
                        d2 += grid[i + k][j + side - 1 - k];
                    }
                    st.insert(d2);

                    if (st.size() == 1) {
                        ans = max(ans, side);
                    }
                }
            }
        }
        return ans;
    }
};
