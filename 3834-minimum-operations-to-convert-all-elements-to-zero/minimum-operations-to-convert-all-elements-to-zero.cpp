class Solution {
public:
    int minOperations(vector<int>& nums) {
          vector<int> st;
        int c = 0;
        for (int ele : nums) {
            while (!st.empty() && st.back() > ele)
                st.pop_back();
            if (ele == 0) continue;
            if (st.empty() || st.back() < ele) {
                st.push_back(ele);
                c++;
            }
        }
        return c;
    }
};