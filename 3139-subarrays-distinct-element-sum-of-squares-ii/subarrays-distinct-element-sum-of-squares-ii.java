class Solution {
    static class Node {
        long cnt = 0;
        long sq_cnt = 0;
        long lazy = 0;
    }

    private static final int MOD = 1000000007;
    private Node[] tree;
    private int[] lastSeen;

    private void apply(int node, int st, int end, long x) {
        long len = end - st + 1;
        tree[node].sq_cnt = (tree[node].sq_cnt + 2 * x * tree[node].cnt % MOD + x * x % MOD * len % MOD) % MOD;
        tree[node].cnt = (len * x % MOD + tree[node].cnt) % MOD;
        tree[node].lazy = (tree[node].lazy + x) % MOD;
    }

    private void lazyPropagation(int node, int st, int end) {
        if (tree[node].lazy == 0) return;
        long x = tree[node].lazy;
        int mid = st + (end - st) / 2;
        apply(2 * node, st, mid, x);
        apply(2 * node + 1, mid + 1, end, x);
        tree[node].lazy = 0;
    }

    private void merge(int node, int left, int right) {
        tree[node].cnt = (tree[left].cnt + tree[right].cnt) % MOD;
        tree[node].sq_cnt = (tree[left].sq_cnt + tree[right].sq_cnt) % MOD;
    }

    private void update(int node, int st, int end, int ql, int qr) {
        if (qr < st || end < ql) return;
        if (ql <= st && end <= qr) {
            apply(node, st, end, 1);
            return;
        }
        lazyPropagation(node, st, end);
        int mid = st + (end - st) / 2;
        update(2 * node, st, mid, ql, qr);
        update(2 * node + 1, mid + 1, end, ql, qr);
        merge(node, 2 * node, 2 * node + 1);
    }

    public int sumCounts(int[] nums) {
        int n = nums.length;
        int maxVal = 0;
        for (int num : nums) {
            maxVal = Math.max(maxVal, num);
        }

        tree = new Node[4 * n + 1];
        for (int i = 0; i <= 4 * n; i++) {
            tree[i] = new Node();
        }

        lastSeen = new int[maxVal + 1];
        Arrays.fill(lastSeen, -1);

        long ans = 0;
        for (int i = 0; i < n; i++) {
            int st = (lastSeen[nums[i]] == -1) ? 0 : lastSeen[nums[i]] + 1;
            lastSeen[nums[i]] = i;
            update(1, 0, n - 1, st, i);
            ans = (tree[1].sq_cnt + ans) % MOD;
        }

        return (int) ans;
    }
}