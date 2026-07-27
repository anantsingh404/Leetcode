class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first=-1;
        int sec=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>first)
            {   sec=first;
                first=nums[i];

            }
            else if(nums[i]>sec)
            {
                sec=nums[i];
            }
        }
        return (first-1)*(sec-1);
    }
};