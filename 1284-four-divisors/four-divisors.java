class Solution {
    public int sumFourDivisors(int[] nums) {
      int ans = 0;

        for (int n : nums) {
            int count = 0;
            int sum = 0;

            for (int d = 1; d * d <= n; d++) {
                if (n % d == 0) {
                    int other = n / d;

                    if (d == other) {
                        count += 1;
                        sum += d;
                    } else {
                        count += 2;
                        sum += d + other;
                    }
                }
            }

            if (count == 4) {
                ans += sum;
            }
        }

        return ans;   
    }
}