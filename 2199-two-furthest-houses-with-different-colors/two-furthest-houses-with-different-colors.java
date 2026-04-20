class Solution {
    public int maxDistance(int[] colors) {
        int n = colors.length;
        int ans = 0;

        // compare with first element
        for (int i = n - 1; i >= 0; i--) {
            if (colors[i] != colors[0]) {
                ans = Math.max(ans, i - 0);
                break;
            }
        }

        // compare with last element
        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[n - 1]) {
                ans = Math.max(ans, (n - 1) - i);
                break;
            }
        }

        return ans;
    }
}