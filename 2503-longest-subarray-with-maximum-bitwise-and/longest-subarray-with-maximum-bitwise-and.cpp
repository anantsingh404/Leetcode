class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int maxi=*max_element(nums.begin(),nums.end());
       int ans=0;
       int i=0;
       while(i<nums.size())
       { 
        int j=i;
        int count=0;
        while(j<nums.size() && nums[i]==nums[j] && nums[i]==maxi)
        {
            ++count;
            j++;
        }
        if(i==j)
        {
            ++i;
        }
        else
        {
            i=j;
        }
        ans=max(ans,count);
       }
       return ans; 
    }
};