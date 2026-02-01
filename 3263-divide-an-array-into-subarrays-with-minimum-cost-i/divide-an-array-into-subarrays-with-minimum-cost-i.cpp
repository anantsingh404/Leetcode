class Solution {
public:
    int minimumCost(vector<int>& nums) {
      sort(nums.begin()+1,nums.end());
      int n=nums.size();
      return nums[0]+nums[1]+nums[2];  
    }
};