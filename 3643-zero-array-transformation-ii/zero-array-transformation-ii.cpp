class Solution {
public:
  int n;
bool check(vector<int>& nums, vector<vector<int>>& q, int x) {
    vector<int> dp(n, 0);
    
    for (int i = 0; i <= x; i++) {
        int a = q[i][0];
        int b = q[i][1];
        int c = q[i][2];

        dp[a] -= c;
        if (b + 1 < n) {
            dp[b + 1] += c;
        }
    }

    int sum = 0;  // Track prefix sum
    for (int i = 0; i < n; i++) {
        sum += dp[i];
        if (nums[i] + sum > 0) {  // nums[i] should become <= 0
            return false;
        }
    }
    
    return true;
}

int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    n = nums.size();
    int mini = 0, maxi = queries.size() - 1;
    int ans = INT_MAX;
   long long sum=accumulate(nums.begin(),nums.end(),1ll*0);
   if(sum==0)
   {
    return 0;
   }


    while (mini <= maxi) {
        int x = (mini + maxi) / 2;
        if (check(nums, queries, x)) {
            ans = x;
            maxi = x - 1;
        } else {
            mini = x + 1;
        }
    }
    

    return (ans == INT_MAX) ? -1 : ans + 1;
}
};