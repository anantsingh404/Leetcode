class Solution {
public:
    int maximumLength(vector<int>& nums) {
      int o=0;;
      int e=0;
      if(nums.size()<=1)
      {
        return 1;
      }

      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]%2)
        {
            ++o;
        }
        else
        {
            ++e;
        }
      } 
      int ans=2;
      ans=max(ans,e);
      ans=max(ans,o);
      int parity=0;
      o=0;
      for(int i=0;i<nums.size();i++)
      {
        if(parity==0 && nums[i]%2)
        {
            ++o;
            parity=1;
        }
        else if(parity==1 && nums[i]%2==0)
        {
            ++o;
            parity=0;
        }
      } 
      ans=max(ans,o);
        parity=0;
      o=0;
      for(int i=0;i<nums.size();i++)
      {
        if(parity==0 && nums[i]%2==0)
        {
            ++o;
            parity=1;
        }
        else if(parity==1 && nums[i]%2)
        {
            ++o;
            parity=0;
        }
      } 
      ans=max(ans,o);
      return ans;
    }
};