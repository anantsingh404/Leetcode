class Solution {
public:
int countHillValley(vector<int>& nums) {
    vector<int> unique;
    for (int x : nums) {
        if (unique.empty() || unique.back() != x) {
            unique.push_back(x);
        }
    }

    int count = 0;
    for (int i = 1; i + 1 < unique.size(); ++i) {
        if ((unique[i] > unique[i - 1] && unique[i] > unique[i + 1]) || 
            (unique[i] < unique[i - 1] && unique[i] < unique[i + 1])) {
            ++count;
        }
    }
    return count;
}

};