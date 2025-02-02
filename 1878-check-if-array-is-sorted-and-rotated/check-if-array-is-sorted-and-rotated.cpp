class Solution {
public:
    bool check(vector<int>& nums) {
      int i=0;
      int x,count;
      while(i<nums.size()-1)
      {
        if(nums[i]>nums[i+1])
        {
            int x=i;
            ++count;
        }
        i++;
      } 
      if(count==0)
      {
        return true;
      }
      if(count>1)
      {
        return false;
      }
      if(nums[0]<nums[nums.size()-1])
      {
        return false;
      }
      return count<=1; 
    }
};