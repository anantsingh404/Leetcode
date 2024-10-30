class Solution {
public:
int lis(vector<int>&nums)
{
    int n = nums.size();
    vector<int> ans;
    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
               ans.push_back(nums[i]);
        }
        else {
             int low = lower_bound(ans.begin(), ans.end(),
                                  nums[i])
                      - ans.begin();
                        ans[low] = nums[i];
        }
    }
    return (int)ans.size();
}
int lds(vector<int>&nums)
{
    int n = nums.size();
    vector<int> ans;
   
    reverse(nums.begin(),nums.end());
     ans.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
               ans.push_back(nums[i]);
        }
        else {
             int low = lower_bound(ans.begin(), ans.end(),
                                  nums[i])
                      - ans.begin();
                        ans[low] = nums[i];
        }
    }
    return (int)ans.size();
}
    int minimumMountainRemovals(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
      for(int i=1;i<n-1;i++)
      {
        vector<int>right;
        vector<int>left;
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                left.push_back(nums[j]);
            }
        }
         for(int j=i+1;j<n;j++)
        {
            if(nums[j]<nums[i])
            {
                right.push_back(nums[j]);
            }
        }
        if(left.empty() || right.empty())
        {
            continue;
        }
        
        int x=lis(left);
        int y=lds(right);
        cout<<x<<" "<<y<<" "<<i<<endl;
        ans=min(ans,n-x-y-1);

      } 
      return ans; 
    }
};