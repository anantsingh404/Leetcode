class Solution {
public:
   vector<string> findAllRecipes(vector<string>& re, vector<vector<string>>& in, vector<string>& su) {
    unordered_map<string, int> mp;
    for (const string& s : su) {
        mp[s]++;
    }

    queue<pair<string, int>> q;
    for (int i = 0; i < re.size(); i++) {
        q.push({re[i], i});
    }

    int processed = 0;
    int k=40000;
    while (!q.empty() && k--) {
        bool canMake = true;
        auto [recipe, idx] = q.front();
        q.pop();

        // Check if all ingredients are available
        for (const string& ingredient : in[idx]) {
            if (mp.count(ingredient) == 0) {
                canMake = false;
                break;
            }
        }

        // If recipe can be made, mark it as a new supply
        if (canMake) {
            mp[recipe]++;
            processed++; // Track successfully processed recipes
        } else {
            q.push({recipe, idx});
        }
    }

    vector<string> anss;
    for (const string& recipe : re) {
        if (mp.count(recipe)) {
            anss.push_back(recipe);
        }
    }

    return anss;
}
};