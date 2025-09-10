class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& l, vector<vector<int>>& f) {
         vector<pair<int,int>> vp;

    // Convert all user's language lists to sets for fast lookup
    int m = l.size();
    vector<unordered_set<int>> langs(m);
    for (int i = 0; i < m; ++i) {
        for (int lang : l[i]) {
            langs[i].insert(lang);
        }
    }

    // Step 1: Identify uncommunicative pairs
    for (auto& itr : f) {
        int x = itr[0] - 1;
        int y = itr[1] - 1;
        bool canCommunicate = false;
        for (int lang : langs[x]) {
            if (langs[y].count(lang)) {
                canCommunicate = true;
                break;
            }
        }
        if (!canCommunicate) {
            vp.push_back({x + 1, y + 1});  // 1-based indexing
        }
    }

    // Step 2: Brute force check for each language
    int res = INT_MAX;
    for (int lang = 1; lang <= n; ++lang) {
        unordered_set<int> toTeach;
        for (auto& [u, v] : vp) {
            if (!langs[u - 1].count(lang)) {
                toTeach.insert(u - 1);
            }
            if (!langs[v - 1].count(lang)) {
                toTeach.insert(v - 1);
            }
        }
        res = min(res, (int)toTeach.size());
    }

    return res;
    }
};