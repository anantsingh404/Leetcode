class Solution {
public:
    const int mod = 1e9+7;

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> r(n);
        deque<int> mn, mx;

        int right = 0;
        for (int left = 0; left < n; left++) {
            while (right < n) {
                while (!mn.empty() && nums[mn.back()] >= nums[right]) {
                    mn.pop_back();
                }
                mn.push_back(right);

                while (!mx.empty() && nums[mx.back()] <= nums[right]) {
                    mx.pop_back();
                }
                mx.push_back(right);

                if (nums[mx.front()] - nums[mn.front()] > k) {
                    break;
                }
                right++;
            }

            r[left] = right - 1;

            if (!mn.empty() && mn.front() == left) mn.pop_front();
            if (!mx.empty() && mx.front() == left) mx.pop_front();
        }

        vector<int> dp(n+1, 0), pref(n+2, 0);
        dp[n] = 1;
        pref[n] = 1;

        for (int i = n-1; i >= 0; --i) {
            dp[i] = pref[i+1];
            if (r[i] + 2 <= n) {
                dp[i] = (dp[i] - pref[r[i] + 2] + mod) % mod;
            }
            pref[i] = (dp[i] + pref[i+1]) % mod;
        }

        return dp[0];
    }
};