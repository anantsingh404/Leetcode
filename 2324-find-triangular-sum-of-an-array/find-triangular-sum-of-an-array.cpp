class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        int m=n;
        while(m>1)
        {
           for(int i=0;i<m-1;i++){
             nums[i]=(nums[i]+nums[i+1])%10;
           }
           --m;
        }
        return nums[0];

    }
};