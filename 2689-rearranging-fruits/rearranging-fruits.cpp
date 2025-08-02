class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
          long long cost = 0;
    unordered_map<int, int> mp1, mp2, mp;
    int mini1 = INT_MAX;

    for (int x : b1) {
        mp1[x]++;
        mp[x]++;
        mini1 = min(mini1, x);
    }

    for (int x : b2) {
        mp2[x]++;
        mp[x]++;
        mini1 = min(mini1, x);
    }

    for (auto& [key, val] : mp) {
        if (val % 2 != 0) return -1;
    }

    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int> pq2;

    for (auto& [val, total] : mp) {
        int half = total / 2;
        int extra1 = mp1[val] - half;
        int extra2 = mp2[val] - half;

        while (extra1-- > 0) pq1.push(val);
        while (extra2-- > 0) pq2.push(val);
    }

    while (!pq1.empty() && !pq2.empty()) {
        int x = min(pq1.top(), pq2.top());
        cost += min(x, 2 * mini1);
        pq1.pop();
        pq2.pop();
    }

    return cost;
  
    }
};