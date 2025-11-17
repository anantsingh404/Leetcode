class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
      int last=-1e6;
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]==1)
       {
        if(i-last<=k)
        {
            return false;
        }
        last=i;
       }
      }
      return true;  
    }
};