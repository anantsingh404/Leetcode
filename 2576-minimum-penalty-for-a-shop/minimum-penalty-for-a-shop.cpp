class Solution {
public:
    int bestClosingTime(string cust) {
          int n = cust.size();

    vector<int> prefixY(n + 1, 0);
    vector<int> suffixY(n + 1, 0);

    // prefixY[i] = number of 'Y' in [0 .. i-1]
    for (int i = 0; i < n; i++) {
        prefixY[i + 1] = prefixY[i] + (cust[i] == 'Y');
    }

    // suffixY[i] = number of 'Y' in [i .. n-1]
    for (int i = n - 1; i >= 0; i--) {
        suffixY[i] = suffixY[i + 1] + (cust[i] == 'Y');
    }

    int ans = INT_MAX;
    int res = 0;

    for (int i = 0; i <= n; i++) {
        int penalty = (i - prefixY[i]) + suffixY[i];
        if (penalty < ans) {
            ans = penalty;
            res = i;
        }
    }

    return res;
    }
};