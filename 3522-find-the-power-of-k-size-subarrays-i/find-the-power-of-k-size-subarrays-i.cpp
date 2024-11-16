class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
    if (k == 1) {
        return nums;
    }

    set<int> st;
    vector<int> ans;
    int i = 1;

    while (i < n) {
        if (nums[i] - nums[i - 1] == 1) {
            if (st.empty()) {
                if (i >= k - 1) {
                    ans.push_back(nums[i]);
                }
            } else if(!st.empty() && i>=k-1){
                auto itr = st.end();
                --itr;
                if (i - (*itr) >= k) {
                    ans.push_back(nums[i]);
                }
                else
                {
                    ans.push_back(-1);
                }
            }
        } else {
            if(i>=k-1)
            {
            ans.push_back(-1);
            }
            st.insert(i - 1);
        }
        i++;
    }

    return ans;
    }
};