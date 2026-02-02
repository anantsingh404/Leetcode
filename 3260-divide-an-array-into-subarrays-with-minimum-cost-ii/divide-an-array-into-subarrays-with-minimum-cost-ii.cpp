#define ll long long int
class Solution {
    multiset<ll> l, r;
public:
    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        k--;
        ll cur = nums[0];
        for (int i = 1; i <= dist + 1; i++) cur += nums[i], l.insert(nums[i]);
        while (l.size() > k) {
            cur -= *l.rbegin();
            r.insert(*l.rbegin());
            l.erase(l.find(*l.rbegin()));
        }

        ll ans = cur;
        for (int i = dist + 2; i < n; i++) {
            if (l.find(nums[i - dist - 1]) != l.end()) {
                cur -= nums[i - dist - 1];
                l.erase(l.find(nums[i - dist - 1]));
            } else {
                r.erase(r.find(nums[i - dist - 1]));
            }
            if (nums[i] < *l.rbegin()) {
                cur += nums[i];
                l.insert(nums[i]);
            } else {
                r.insert(nums[i]);
            }
            while (l.size() < k) {
                cur += *r.begin();
                l.insert(*r.begin());
                r.erase(r.find(*r.begin()));
            }
            while (l.size() > k) {
                cur -= *l.rbegin();
                r.insert(*l.rbegin());
                l.erase(l.find(*l.rbegin()));
            }
            ans = min(ans, cur);
        }
        return ans;
    }
};
