class Solution {
public:
    int minPairSum(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int maxi=0;
      int n=nums.size();
      int i=0;
      int j=n-1;
      while(i<j)
      {
        maxi=max(maxi,nums[i]+nums[j]);
        i++;
        j--;
      } 
      return maxi; 
    }
};