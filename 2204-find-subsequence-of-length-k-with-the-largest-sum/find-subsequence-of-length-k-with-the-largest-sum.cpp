class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
       vector<int>dp=nums;
       sort(nums.begin(),nums.end());
       int i=nums.size()-1;
       multiset<int>st;
       while(i>=0 && k)
       {
        st.insert(nums[i]);
        i--;
        k--;
       } 
      // cout<<st.size()<<endl;
       vector<int>ans;
       for(int i=0;i<dp.size();i++)
       {
        if(st.lower_bound(dp[i])!=st.end() && *st.lower_bound(dp[i])==dp[i])
        {    
           // cout<<dp[i]<<endl;
            ans.push_back(dp[i]);
            st.erase(st.lower_bound(dp[i]));
        }
       }
       return ans;
    }
};