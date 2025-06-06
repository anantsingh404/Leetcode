class Solution {
public:
    string robotWithString(string s) {
          int n = s.size();
    vector<char> minRight(n);
    
    // Fill minRight[i] = minimum character in s[i..n-1]
    minRight[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        minRight[i] = min(s[i], minRight[i + 1]);
    }

    string t, ans;
    for (int i = 0; i < n; ++i) {
        t.push_back(s[i]);

        // While the top of stack is <= the smallest remaining char
        while (!t.empty() && (i == n - 1 || t.back() <= minRight[i + 1])) {
            ans.push_back(t.back());
            t.pop_back();
        }
    }

    return ans;
    }
};