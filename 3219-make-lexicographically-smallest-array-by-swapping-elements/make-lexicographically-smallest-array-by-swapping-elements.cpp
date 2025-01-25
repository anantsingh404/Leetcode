class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

    // Step 1: Pair elements with their original indices
    vector<pair<int, int>> paired;
    for (int i = 0; i < n; ++i) {
        paired.push_back({nums[i], i});
    }

    // Step 2: Sort the paired array by the element values
    sort(paired.begin(), paired.end());

    // Step 3: Group elements based on the `limit`
    vector<vector<pair<int, int>>> groups;
    groups.push_back({paired[0]}); // Start with the first element
    int group_idx = 0;

    for (int i = 1; i < n; ++i) {
        // If the absolute difference with the last element of the current group <= limit
        if (abs(paired[i].first - groups[group_idx].back().first) <= limit) {
            groups[group_idx].push_back(paired[i]);
        } else {
            // Start a new group
            groups.push_back({paired[i]});
            group_idx++;
        }
    }

    // Step 4: Sort indices within each group to maintain lexicographical order
    for (auto& group : groups) {
        // Sort the group by the original indices to prepare for reconstruction
        sort(group.begin(), group.end());
    }

    // Step 5: Reconstruct the result array
    vector<int> result(n);
    for(int i=0;i<groups.size();i++)
    {    vector<int>idx;
        for(int j=0;j<groups[i].size();j++)
        {
            idx.push_back(groups[i][j].second);
        }
        sort(idx.begin(),idx.end());
        for(int j=0;j<groups[i].size();j++)
        {
          result[idx[j]]=groups[i][j].first;
        }
    }

    return result;
    }
};