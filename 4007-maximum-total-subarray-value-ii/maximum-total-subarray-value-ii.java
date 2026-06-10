import java.util.*;

class Solution {

    static class PQNode {
        int i;
        int j;
        long val;

        PQNode(int i, int j, long val) {
            this.i = i;
            this.j = j;
            this.val = val;
        }
    }

    static class SegmentTree {

        static class Node {
            int start;
            int end;
            int mn;
            int mx;

            Node left;
            Node right;

            Node(int start, int end) {
                this.start = start;
                this.end = end;
                this.mn = Integer.MAX_VALUE;
                this.mx = Integer.MIN_VALUE;
            }
        }

        Node root;

        SegmentTree(int[] nums) {
            root = buildTree(nums, 0, nums.length - 1);
        }

        private Node buildTree(int[] nums, int start, int end) {

            Node node = new Node(start, end);

            if (start == end) {
                node.mn = nums[start];
                node.mx = nums[start];
                return node;
            }

            int mid = (start + end) / 2;

            node.left = buildTree(nums, start, mid);
            node.right = buildTree(nums, mid + 1, end);

            node.mn = Math.min(node.left.mn, node.right.mn);
            node.mx = Math.max(node.left.mx, node.right.mx);

            return node;
        }

        private int[] query(Node node, int start, int end) {

            if (node == null) {
                return new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE};
            }

            if (start <= node.start && node.end <= end) {
                return new int[]{node.mn, node.mx};
            }

            if (node.end < start || end < node.start) {
                return new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE};
            }

            int[] left = query(node.left, start, end);
            int[] right = query(node.right, start, end);

            int mn = Math.min(left[0], right[0]);
            int mx = Math.max(left[1], right[1]);

            return new int[]{mn, mx};
        }

        public int[] query(int start, int end) {
            return query(root, start, end);
        }
    }

    public long maxTotalValue(int[] nums, int k) {

        int n = nums.length;

        SegmentTree st = new SegmentTree(nums);

        PriorityQueue<PQNode> pq = new PriorityQueue<>(
                (a, b) -> Long.compare(b.val, a.val)
        );

        for (int i = 0; i < n; i++) {

            int j = n - 1;

            int[] res = st.query(i, j);

            long val = (long) res[1] - res[0];

            pq.offer(new PQNode(i, j, val));
        }

        long ans = 0;

        while (k-- > 0) {

            PQNode peak = pq.poll();

            ans += peak.val;

            int i = peak.i;
            int j = peak.j - 1;

            if (i <= j) {

                int[] res = st.query(i, j);

                long val = (long) res[1] - res[0];

                pq.offer(new PQNode(i, j, val));
            }
        }

        return ans;
    }
}