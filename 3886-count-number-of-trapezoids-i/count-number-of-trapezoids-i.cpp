class Solution {
public:
    const int mod = 1e9 + 7;

static bool cmp(vector<int>& a, vector<int>& b)
{
    if (b[1] == a[1]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int countTrapezoids(vector<vector<int>>& points) 
{
    sort(points.begin(), points.end(), cmp);

    int n = points.size();
    long long count = 0;
    long long ans = 0;

    int i = 0;
    while (i < n) 
    {
        long long j = 0;

        while (i + j < n && points[i][1] == points[i + j][1]) {
            j++;
        }

        if (j > 0) {
            i += j;
        }
        else {
            i++;
        }

        if (j >= 2)
        {
            long long pairs = (j * (j - 1) / 2) % mod;

            // ans += count * pairs
            long long addVal = (count % mod * pairs % mod) % mod;
            ans = (ans + addVal) % mod;

            // count += pairs
            count = (count + pairs) % mod;
        }
    }

    return ans % mod;
}
};