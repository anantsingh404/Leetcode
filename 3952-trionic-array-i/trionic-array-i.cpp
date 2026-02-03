class Solution {
public:
    bool isTrionic(vector<int>& nums) {
      int count=0;
      if(nums.size()<3)
      {
        return false;
      }
      if(nums[1]<=nums[0])
      {
        return false;
      }
      ++count;
      int turn=0;
      for(int i=2;i<nums.size();i++)
      {
        if(nums[i]<nums[i-1] && turn==0)
      {
         ++count;
         turn=1;
      }
      else if(nums[i]>nums[i-1] && turn==1)
      {
        ++count;
        turn=0;
      }
      else if(nums[i]==nums[i-1]){
        return false;

      }
      }return count==3;  
    }
};