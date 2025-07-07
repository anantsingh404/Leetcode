class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

    vector<int> parent;

    int find(int day) {
        if (parent[day] != day) {
            parent[day] = find(parent[day]); // path compression
        }
        return parent[day];
    }

    int maxEvents(vector<vector<int>>& e) {
        int n = e.size();
        sort(e.begin(), e.end(), cmp);

        int maxDay = 0;
        for (auto &it : e) {
            maxDay = max(maxDay, it[1]);
        }

        parent.resize(maxDay + 2);
        for (int i = 0; i <= maxDay + 1; ++i) parent[i] = i;

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int availableDay = find(e[i][0]);
            if (availableDay <= e[i][1]) {
                sum++;
                parent[availableDay] = availableDay + 1; // mark next available day
            }
        }
        return sum;
    }
};
