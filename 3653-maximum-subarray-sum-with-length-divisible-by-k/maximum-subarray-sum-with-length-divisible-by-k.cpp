class Solution {
public:
    vector<long long> pf;
    long long maxSubarraySum(vector<int>& nums, int k) {
     long long res = LLONG_MIN;
    int n = nums.size();
    long long cur = 0;
        pf.assign(n,LLONG_MAX);
    pf[0] = 0;
    int i = 1;
    while (i <= n)
        {
        int r = i % k;
        cur += nums[i-1];
      
        if (pf[r] != LLONG_MAX) 
        {
            res = max(res, cur-pf[r]);
        }
        pf[r] = min(pf[r], cur);
        i++;
    }
    
    return res;
    }
};