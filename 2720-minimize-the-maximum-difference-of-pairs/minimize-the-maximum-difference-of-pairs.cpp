class Solution {
public:
bool s(vector<int>&nums,int mid,int p)
{
     int cnt = 0;
    int i = 0;
    int n = nums.size();
    while (i < n - 1) {
        if (nums[i + 1] - nums[i] <= mid) {
            cnt++;
            i += 2; // skip both indices
        } else {
            i += 1;
        }
    }
    return cnt >= p;
}
    int minimizeMax(vector<int>& nums, int p) {
      sort(nums.begin(),nums.end());
       int mini=0;
       int maxi=1e9;
       int ans=INT_MAX;
       while(mini<=maxi)
       {
        int mid=(mini+maxi)/2;
        if(s(nums,mid,p))
        {
            ans=mid;
            maxi=mid-1;
        }
        else
        {
            mini=mid+1;
        }
       } 
       return ans;
    }
};