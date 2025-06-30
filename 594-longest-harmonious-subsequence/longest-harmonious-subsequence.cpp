class Solution {
public:
    int findLHS(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     int ans=0;
     int n=nums.size();
     for(int i=0;i<nums.size()-1;i++)
     {
        int idx=upper_bound(nums.begin()+i,nums.end(),nums[i]+1)-nums.begin();
        --idx;
        if(idx<n && nums[idx]-nums[i]==1)
        {
            ans=max(ans,idx-i+1);
        }
     }  
     return ans; 
    }
};