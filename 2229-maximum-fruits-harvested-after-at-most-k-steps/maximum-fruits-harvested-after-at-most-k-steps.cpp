class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& f, int sp, int k) {
        int n = f.size();
    vector<int> right(4*1e5 +1, 0); // +2 for safe bounds

    for (int i = 0; i < n; i++) {
        right[f[i][0]] = f[i][1];
    }

    for (int i = 1; i <= 4*1e5; i++) {
        right[i] = right[i - 1] + right[i];
    }

    int ans = 0;

    // Case 1: go left first, then maybe right
    int i = sp;
    while (i >= 0 && i >= sp - k) {
        int sum = right[sp];
        if (i > 0) {
            sum -= right[i - 1];
        }
        int p = sp - i;
        if (k > 2 * p) {
            int rem = k - 2 * p;
            int idx = min((int)(4*1e5), sp + rem);
            // ❗ exclude sp itself to avoid double counting
            if (sp < idx)
                sum += right[idx] - right[sp];
        }
        ans = max(ans, sum);
       // cout<<ans<<endl;
        i--;
    }

    // Case 2: go right first, then maybe left
    i = sp;
    while (i <= 4*1e5 && i <= sp + k) {
        int sum = right[i];
        if (sp > 0) {
            sum -= right[sp - 1];
        }
        int p = i - sp;
        if (k > 2 * p) {
            int rem = k - 2 * p;
            int idx = max(0, sp - rem);
            // ❗ exclude sp itself to avoid double counting
            if (idx < sp) {
                if (idx > 0)
                    sum += right[sp - 1] - right[idx - 1];
                else
                    sum += right[sp - 1];
            }
        }
        ans = max(ans, sum);
        i++;
    }

    return ans;
    }
};