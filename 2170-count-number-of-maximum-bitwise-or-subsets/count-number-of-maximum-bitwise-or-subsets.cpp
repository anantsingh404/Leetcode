class Solution {
public:
int count=0;
int maxi=0;
int n;
    void solve(int idx,vector<int>&nums,int temp)
    {    if(idx==n)
        {   if(temp==maxi)
        {
            ++count;
        }
            return;
        }
       
       

        solve(idx+1,nums,temp|nums[idx]);
        solve(idx+1,nums,temp);
    }
    int countMaxOrSubsets(vector<int>& nums) {
     // int maxi=0;
     n=nums.size();
      for(int i=0;i<nums.size();i++)
      {
        maxi=maxi|nums[i];
      } 
      solve(0,nums,0);
      return count;

    }
};