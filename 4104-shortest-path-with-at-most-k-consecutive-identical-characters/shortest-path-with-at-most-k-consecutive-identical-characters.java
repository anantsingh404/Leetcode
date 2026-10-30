import java.util.*;

class Solution {
    public int shortestPath(int n, int[][] edges, String labels, int k) {
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj.get(u).add(new int[]{v, w});
        }

        long[][] dist = new long[n][k + 1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dist[i], Long.MAX_VALUE / 2);
        }

        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));

        dist[0][1] = 0;
        pq.add(new long[]{0, 0, 1});

        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            long d = curr[0];
            int u = (int) curr[1];
            int r = (int) curr[2];

            if (d > dist[u][r]) {
                continue;
            }

            for (int[] neighbor : adj.get(u)) {
                int v = neighbor[0];
                int w = neighbor[1];

                int newr = 1;
                if (labels.charAt(v) == labels.charAt(u)) {
                    newr = r + 1;
                }

                if (newr > k) {
                    continue;
                }

                long nd = d + w;
                if (nd < dist[v][newr]) {
                    dist[v][newr] = nd;
                    pq.add(new long[]{nd, v, newr});
                }
            }
        }

        long sol = Long.MAX_VALUE / 2;
        for (int i = 0; i <= k; i++) {
            sol = Math.min(sol, dist[n - 1][i]);
        }

        if (sol >= Long.MAX_VALUE / 2) {
            return -1;
        }

        return (int) sol;
    }
}
