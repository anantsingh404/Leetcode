class Solution {
    public boolean canReach(int[] arr, int s) {
          Queue<Integer> q = new LinkedList<>();

        int n = arr.length;
        int vis[] = new int[n];

        vis[s] = 1;
        q.add(s);

        while (q.size() > 0) {
            int x = q.peek();
            q.poll();

            int p = x - arr[x];
            int r = x + arr[x];

            if (p >= 0 && vis[p] == 0) {
                vis[p] = 1;
                q.add(p);
            }

            if (r < n && vis[r] == 0) {
                vis[r] = 1;
                q.add(r);
            }
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] == 1 && arr[i] == 0) {
                return true;
            }
        }

        return false;
    }
}