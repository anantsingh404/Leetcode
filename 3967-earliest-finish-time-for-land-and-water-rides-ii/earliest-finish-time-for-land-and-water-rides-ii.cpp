class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
    int n = ld.size();
    int m = wd.size();
    vector<pair<int, int>> a, b;
    vector<int> c, d, e(n), f(m);
    vector<long long> g(n), h(m);
    int i = 0;
    while (i < n)
    {
        a.push_back({lst[i], ld[i]});
        ++i;
    }
    i = 0;
    while (i < m) 
    {
        b.push_back({wst[i], wd[i]});
        ++i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    i = 0;
    while (i < n)
    {
        c.push_back(a[i].first);
        ++i;
    }
    i = 0;
    while (i < m)
    {
        d.push_back(b[i].first);
        ++i;
    }
    e[0] = a[0].second;
    i = 1;
    while (i < n) 
    {
        e[i] = min(e[i - 1], a[i].second);
        ++i;
    }
    f[0] = b[0].second;
    i = 1;
    while (i < m) 
    {
        f[i] = min(f[i - 1], b[i].second);
        ++i;
    }
    g[n - 1] = 1LL * a[n - 1].first + a[n - 1].second;
    i = n - 2;
    while (i >= 0) 
    {
        g[i] = min(g[i + 1], 1LL * a[i].first + a[i].second);
        --i;
    }
    h[m - 1] = 1LL * b[m - 1].first + b[m - 1].second;
    i = m - 2;
    while (i >= 0) 
    {
        h[i] = min(h[i + 1], 1LL * b[i].first + b[i].second);
        --i;
    }
    long long res = LLONG_MAX;
    i = 0;
    while (i < m) 
    {
        long long y = 1LL * wst[i] + wd[i];
        int j = upper_bound(c.begin(), c.end(), y) - c.begin() - 1;
        if (j >= 0) {
            res = min(res, y + e[j]);
        }
        if (j + 1 < n) {
            res = min(res, g[j + 1]);
        }
        ++i;
    }
    i = 0;
    while (i < n)
    {
        long long x = 1LL * lst[i] + ld[i];
        int j = upper_bound(d.begin(), d.end(), x) - d.begin() - 1;
        if (j >= 0) 
        {
            res = min(res, x + f[j]);
        }
        if (j + 1 < m) {
            res = min(res, h[j + 1]);
        }
        ++i;
    }
    return (int)res;
    }
};