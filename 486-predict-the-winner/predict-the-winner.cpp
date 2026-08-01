class Solution {
public:
int solve(vector<int>&nums,int i,int j)
{
    if(i==j)
    {
        return nums[i];
    }int diff1=nums[i]-solve(nums,i+1,j);
    int diff2=nums[j]-solve(nums,i,j-1);
    return max(diff1,diff2);
}
    bool predictTheWinner(vector<int>& nums) {
       int n=nums.size();
       return (int)solve(nums,0,n-1)>=0;

    }
};