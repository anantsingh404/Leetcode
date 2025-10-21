class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
      int ans = 1;
        sort(nums.begin(), nums.end());
        for (int target = nums[0]; target <= nums[nums.size() - 1]; target++) {
            
            int right = upper_bound(nums.begin(), nums.end(), target + k) -
                        nums.begin();
            int left = lower_bound(nums.begin(), nums.end(), target - k) -
                       nums.begin(); 
            int total_ele=right-left;
            
            int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            int noOpEle = ub - lb;

            
            if (total_ele - noOpEle <= numOperations) {
                ans = max(ans, right - left);
            } else { 
                ans = max(ans, numOperations + noOpEle);
            }
        }
        return ans;  
    }
};