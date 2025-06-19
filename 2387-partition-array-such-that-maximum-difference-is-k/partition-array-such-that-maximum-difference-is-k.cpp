class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
      sort(nums.begin(),nums.end());
      int count=1;
      for(int i=0;i<n;)
      {
        int idx=upper_bound(nums.begin(),nums.end(),nums[i]+k)-nums.begin();
        if(idx<n)
        {
            ++count;
            i=idx;
        }
        else
        {
            break;
        }

      } 
      return count; 
    }
};