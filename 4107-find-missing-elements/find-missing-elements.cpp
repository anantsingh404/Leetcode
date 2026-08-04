class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
     vector<int>dp(101,0) ;
     int small=INT_MAX;
     int large=INT_MIN;
     for(int i=0;i<nums.size();i++)
     {
        small=min(small,nums[i]);
        large=max(large,nums[i]);
        dp[nums[i]]++;
     } 
     vector<int>ans;
     for(int i=small;i<=large;i++)
     {  if(dp[i]==0){
        ans.push_back(i);
     }
     }
     return ans;

    }
};