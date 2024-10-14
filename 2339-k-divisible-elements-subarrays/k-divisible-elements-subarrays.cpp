class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
     set<vector<int>>st;
     for(int i=0;i<nums.size();i++)
     {
        vector<int>ans;
        for(int j=i;j<nums.size();j++)
        {
ans.push_back(nums[j]);
st.insert(ans);
        }
     }
     int ans=0;
     for(auto itr:st)
     {
        int count=0;
        for(int i=0;i<itr.size();i++)
        {
            if(itr[i]%p==0)
            {
                ++count;
            }
        }
        if(count<=k)
        {
            ++ans;
        }
     } 
     return ans;  
    }
};