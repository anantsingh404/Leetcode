class Solution {
    public long[] distance(int[] nums) {
        int n = nums.length;
        long[] dp = new long[n];

        HashMap<Integer, Long> count = new HashMap<>();
        HashMap<Integer, Long> sum = new HashMap<>();

        int i = 0;
        while (i < n) {
            int val = nums[i];

            long c = count.getOrDefault(val, 0L);
            long s = sum.getOrDefault(val, 0L);

            dp[i] = (c * i - s);

            count.put(val, c + 1);
            sum.put(val, s + i);

            i++;
        }

        count.clear();
        sum.clear();

        i = n - 1;
        while (i >= 0) {
            int val = nums[i];

            long c = count.getOrDefault(val, 0L);
            long s = sum.getOrDefault(val, 0L);

            dp[i] = dp[i] + (s - c * i);

            count.put(val, c + 1);
            sum.put(val, s + i);

            i--;
        }

        return dp;
    }
}