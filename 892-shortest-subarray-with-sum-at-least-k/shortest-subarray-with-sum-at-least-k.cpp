class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
      int n = nums.size();
    deque<pair<long long, int>> dq; // {prefix sum, index}
    long long prefixSum = 0; // Use long long to avoid overflow
    int ans = INT_MAX;

    for (int i = 0; i < n; ++i) {
        prefixSum += nums[i];

        // If the current prefix sum itself is >= k
        if (prefixSum >= k) {
            ans = min(ans, i + 1);
        }

        // Remove elements from the front of the deque while we can form a valid subarray
        while (!dq.empty() && prefixSum - dq.front().first >= k) {
            ans = min(ans, i - dq.front().second);
            dq.pop_front();
        }

        // Maintain a monotonic deque by removing elements from the back
        while (!dq.empty() && dq.back().first >= prefixSum) {
            dq.pop_back();
        }

        // Add the current prefix sum and index to the deque
        dq.push_back({prefixSum, i});
    }

    return (ans == INT_MAX) ? -1 : ans;
  
    }
};