
class Solution {
public:

int solve(int idx,vector<int>&nums)
{
    if(idx>=nums.size())
    {
        return 0;
    }
    return max(nums[idx]|solve(idx+1,nums),solve(idx+1,nums));
}
int solve1(int idx,vector<int>&nums,int exor,int x)
{
    if(idx>=nums.size() && exor==x)
    {
        return 1;
    }
    if(idx>=nums.size())
    {
        return 0;
    }
    return solve1(idx+1,nums,exor,x)+solve1(idx+1,nums,exor|nums[idx],x);
}
    int countMaxOrSubsets(vector<int>& nums) {
       int x=solve(0,nums);
        cout<<x<<endl;
        return solve1(0,nums,0,x);
    }
};