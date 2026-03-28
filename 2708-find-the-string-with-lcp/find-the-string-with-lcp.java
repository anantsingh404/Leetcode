import java.util.*;

class Solution {

    int[] parent;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px != py) {
            parent[py] = px;
        }
    }

    public String findTheString(int[][] lcp) {

        int n = lcp.length;

        // Step 1: Basic validation
        int i = 0;
        while (i < n) {
            if (lcp[i][i] != n - i) {
                return "";
            }
            i++;
        }

        // Step 2: DSU init
        parent = new int[n];
        int j = 0;
        while (j < n) {
            parent[j] = j;
            j++;
        }

        // Step 3: Union
        int a = 0;
        while (a < n) {
            int b = 0;
            while (b < n) {
                if (lcp[a][b] > 0) {
                    union(a, b);
                }
                b++;
            }
            a++;
        }

        // Step 4: Assign characters
        char[] res = new char[n];
        Arrays.fill(res, '#');

        char ch = 'a';

        int k = 0;
        while (k < n) {

            int pk = find(k);

            if (res[k] == '#') {

                if (ch > 'z') {
                    return "";
                }

                int t = 0;
                while (t < n) {
                    if (find(t) == pk) {
                        res[t] = ch;
                    }
                    t++;
                }

                ch++;
            }

            k++;
        }

        // Step 5: Validate LCP
        int[][] dp = new int[n][n];

        int x = n - 1;
        while (x >= 0) {
            int y = n - 1;
            while (y >= 0) {

                if (res[x] == res[y]) {
                    if (x == n - 1 || y == n - 1) {
                        dp[x][y] = 1;
                    } else {
                        dp[x][y] = 1 + dp[x + 1][y + 1];
                    }
                } else {
                    dp[x][y] = 0;
                }

                y--;
            }
            x--;
        }

        int p = 0;
        while (p < n) {
            int q = 0;
            while (q < n) {
                if (dp[p][q] != lcp[p][q]) {
                    return "";
                }
                q++;
            }
            p++;
        }

        return new String(res);
    }
}