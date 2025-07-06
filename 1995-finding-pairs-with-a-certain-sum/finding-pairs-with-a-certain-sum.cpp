class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> count2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            count2[num]++;
        }
    }

    void add(int index, int val) {
        // Update count map of nums2
        count2[nums2[index]]--;
        if (count2[nums2[index]] == 0) {
            count2.erase(nums2[index]);
        }
        nums2[index] += val;
        count2[nums2[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (int x : nums1) {
            res += count2[tot - x];
        }
        return res;
    }
};
