class Solution {
    public int minFlips(String s) {
      int n = s.length();
        int diff1 = 0;
        int diff2 = 0;
        int ans = Integer.MAX_VALUE;

        int l = 0;

        for (int r = 0; r < 2 * n; r++) {

            char c = s.charAt(r % n);

            if (c != (r % 2 == 0 ? '0' : '1')) {
                diff1++;
            }

            if (c != (r % 2 == 0 ? '1' : '0')) {
                diff2++;
            }

            if (r - l + 1 > n) {

                char left = s.charAt(l % n);

                if (left != (l % 2 == 0 ? '0' : '1')) {
                    diff1--;
                }

                if (left != (l % 2 == 0 ? '1' : '0')) {
                    diff2--;
                }

                l++;
            }

            if (r - l + 1 == n) {
                ans = Math.min(ans, Math.min(diff1, diff2));
            }
        }

        return ans;  
    }
}