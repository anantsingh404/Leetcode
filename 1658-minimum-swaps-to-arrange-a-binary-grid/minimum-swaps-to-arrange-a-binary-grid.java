class Solution {
    public int minSwaps(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        ArrayList<Integer> ls = new ArrayList<>();

        // Count trailing zeros for each row
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            boolean found = false;

            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    cnt = m - 1 - j;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cnt = m; // row has all zeros
            }

            ls.add(cnt);
        }

        // Feasibility check
        ArrayList<Integer> ls1 = new ArrayList<>(ls);
        Collections.sort(ls1);

        for (int i = 0; i < n; i++) {
            if (ls1.get(i) < i) {
                return -1;
            }
        }

        // Count swaps using greedy
        int count = 0;

        for (int i = 0; i < n; i++) {
            int need = n - i - 1;

            if (ls.get(i) < need) {
                for (int j = i + 1; j < n; j++) {
                    if (ls.get(j) >= need) {
                        count += (j - i);

                        // Bring row j up to i
                        for (int k = j; k > i; k--) {
                            Collections.swap(ls, k, k - 1);
                        }
                        break;
                    }
                }
            }
        }

        return count;  
    }
}