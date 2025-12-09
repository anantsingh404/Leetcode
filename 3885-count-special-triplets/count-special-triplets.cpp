class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod = 1e9 + 7;
    int n = nums.size();

    unordered_map<int,int> mp1, mp2;

    // Count all on the right
    for (int i = 0; i < n; i++) {
        mp2[nums[i]]++;
    }

    long long ans = 0;

    for (int i = 1; i < n - 1; i++) {

        mp1[nums[i - 1]]++;
        mp2[nums[i - 1]]--;

        long long x = nums[i];
        long long key = x * 2;

        long long left = mp1[key];
        long long right = mp2[key];

        if (left > 0 && right > 0)
         {
            long long add = (left % mod) * (right % mod);
            add %= mod;

            if (x != 0) {
                ans = (ans + add) % mod;
            } 
            else {
                
                ans = (ans + add) % mod;

                
                ans = (ans - mp1[0] % mod + mod) % mod;
            }
        }
    }
    return (int)ans;
    }
};