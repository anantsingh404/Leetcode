class Solution {
public:
int sum=0;
int n;
void solve(int idx,vector<int>&nums,int exor)
{
    if(idx>=n)
    {
        sum+=exor;
        return;
    }
    solve(idx+1,nums,exor^nums[idx]);
    solve(idx+1,nums,exor);
}
    int subsetXORSum(vector<int>& nums) {
      n=nums.size();
      solve(0,nums,0);
      return sum; 
    }
};