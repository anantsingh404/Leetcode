class Solution {
    static final int MOD = 1000000007;

    long modExp(long base, long exp) {
        if (exp == 0) return 1;

        long half = modExp(base, exp / 2);
        long result = (half * half) % MOD;

        if (exp % 2 == 1) result = (result * base) % MOD;

        return result;
    }

    public int xorAfterQueries(int[] arr, int[][] ops) {
        int n = arr.length;
        int block = (int)Math.sqrt(n) + 1;

        java.util.List<int[]>[] buckets = new java.util.ArrayList[block];
        for (int i = 0; i < block; i++) {
            buckets[i] = new java.util.ArrayList<>();
        }

        for (int[] query : ops) {
            int left = query[0];
            int right = query[1];
            int step = query[2];
            int val = query[3];

            if (step < block) {
                buckets[step].add(query);
            } else {
                for (int pos = left; pos <= right; pos += step) {
                    arr[pos] = (int)((1L * arr[pos] * val) % MOD);
                }
            }
        }

        for (int step = 1; step < block; step++) {
            if (buckets[step].isEmpty()) continue;

            long[] multiplier = new long[n + step + 5];
            java.util.Arrays.fill(multiplier, 1);

            for (int[] query : buckets[step]) {
                int left = query[0];
                int right = query[1];
                int val = query[3];

                int lastIndex = left + ((right - left) / step) * step;
                int stop = lastIndex + step;

                multiplier[left] = (multiplier[left] * val) % MOD;

                long invVal = modExp(val, MOD - 2);
                multiplier[stop] = (multiplier[stop] * invVal) % MOD;
            }

            for (int i = 0; i < n; i++) {
                if (i - step >= 0) {
                    multiplier[i] = (multiplier[i] * multiplier[i - step]) % MOD;
                }
            }

            for (int i = 0; i < n; i++) {
                arr[i] = (int)((1L * arr[i] * multiplier[i]) % MOD);
            }
        }

        int ans = 0;
        for (int value : arr) {
            ans ^= value;
        }

        return ans;
    }
}