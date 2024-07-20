class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        map<int, vector<int>> diffMap;
        vector<int> vv;

   for (int i = 0; i < nums.size() / 2; ++i) {
    int first = nums[i];
    int second = nums[nums.size() - i - 1];
    int absoluteDiff = abs(first - second);

    int maxX = max({first, second, k - first, k - second});

    diffMap[absoluteDiff].push_back(maxX);
    vv.push_back(maxX);
}

    int minChanges = nums.size();
    sort(vv.begin(), vv.end());

    for (const auto& [diff, values] : diffMap) {
    int totalChanges = lower_bound(vv.begin(), vv.end(), diff) - vv.begin();
    totalChanges = totalChanges * 2 + (nums.size() / 2 - totalChanges);

    for (const auto& maxX : values) {
        if (maxX < diff) {
            totalChanges -= 2;
        } else {
            totalChanges -= 1;
        }
    }

    minChanges = min(minChanges, totalChanges);
}

return minChanges;

    }
};