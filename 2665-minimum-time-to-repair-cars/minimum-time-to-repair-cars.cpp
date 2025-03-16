class Solution {
public:
bool check(long long mid, vector<int>& ranks, int count) {
    for (int i = 0; i < ranks.size(); i++) {
        count -= (long long)sqrt(mid / ranks[i]);
        if (count <= 0) return true; // Break early for efficiency
    }
    return count <= 0;
}

long long repairCars(vector<int>& ranks, int c) {
    long long mini = 1;
    long long maxi = *min_element(ranks.begin(), ranks.end()) * (long long)c * c;
    long long ans = -1;

    while (mini <= maxi) {
        long long mid = (maxi + mini) / 2;
        if (check(mid, ranks, c)) {
            ans = mid;
            maxi = mid - 1;
        } else {
            mini = mid + 1;
        }
    }
    return ans;
}

};