class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
      for(int i=1;i<n;i++)
      {
        for(int j=0;j<i;j++)
        {
            if(nums[i]==nums[j] && (i*j)%k==0)
            {
               ++count;
            }
        }
      } 
      return count; 
    }
};