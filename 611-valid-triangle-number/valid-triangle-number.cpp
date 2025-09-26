class Solution {
public:
    int triangleNumber(vector<int>& nums) {
       int count=0;
       sort(nums.begin(),nums.end());
       int n=nums.size();
       for(int i=0;i<n-2;i++)
       {
        for(int j=i+1;j<n-1;j++)
        {
            int idx=upper_bound(nums.begin()+j+1,nums.end(),nums[i]+nums[j]-1)-nums.begin();
            --idx;
            if(idx>j)
            {
            count+=(idx-j);
            }
        }
        }
        return count; 
    }
};