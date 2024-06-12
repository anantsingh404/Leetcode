class Solution {
public:
    void sortColors(vector<int>& nums) {
      int one=0;
      int zero=0;
      int two=0;
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]==1)
        {
            ++one;
        }
        else if(nums[i]==0)
        {
            ++zero;
        }
        else
        {
            ++two;
        }
      }
      int i=0;
      while(zero)
      {
        nums[i++]=0;
        --zero;
      }
      while(one)
      {
        nums[i++]=1;
        --one;
      }
      while(two)
      {
        nums[i++]=2;
        --two;
      }

    }
};