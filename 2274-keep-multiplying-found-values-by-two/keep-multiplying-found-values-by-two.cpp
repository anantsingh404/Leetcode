class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
       set<int>st(nums.begin(),nums.end());
       while(st.find(o)!=st.end())
       {
        o*=2;
       }
       return o;


    }
};