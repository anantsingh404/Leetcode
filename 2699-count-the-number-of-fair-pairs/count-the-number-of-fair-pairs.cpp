class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
       sort(nums.begin(),nums.end());
       long long count=0;
       for(int i=0;i<nums.size();i++)
       {
        int x=lower-nums[i];
        int y=upper-nums[i];
        
        int p=lower_bound(nums.begin()+i+1,nums.end(),x)-nums.begin();
        int q=upper_bound(nums.begin()+i+1,nums.end(),y)-nums.begin();
       
        count+=q-p;
       }
       return count;

    }
};