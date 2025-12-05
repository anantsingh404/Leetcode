class Solution {
public:
    int countPartitions(vector<int>& nums) {
      int sum=accumulate(nums.begin(),nums.end(),0);
      int count=0;
      int ans=0;
      for(int i=0;i<nums.size()-1;i++)
      {
        count+=nums[i];
        sum-=nums[i];
        if(abs(sum-count)%2==0)
        {
            ++ans;
        }
      } return ans; 
    }
};