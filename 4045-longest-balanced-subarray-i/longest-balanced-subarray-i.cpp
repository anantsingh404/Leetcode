class Solution {
public:
    int longestBalanced(vector<int>& nums) {
           int n = nums.size();
        int ans = 0;

        for (int l = 0; l < n; l++) {
            unordered_map<int,int> freq;
            int even = 0, odd = 0;

            for (int r = l; r < n; r++) {
                if (freq[nums[r]] == 0) {
                    if (nums[r] % 2 == 0) even++;
                    else odd++;
                }
                freq[nums[r]]++;

                if (even == odd) {
                    ans = max(ans, r - l + 1);
                }
            }
        }
        return ans; 
    }
};