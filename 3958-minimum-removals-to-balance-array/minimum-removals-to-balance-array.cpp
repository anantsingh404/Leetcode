class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
     sort(nums.begin(),nums.end());
     int i=0;
     int j=0;
     int n=nums.size();
     int ans=n-1;
     while(i<n)
     {
        while(j<n && nums[j]<=1ll*nums[i]*k)
        {
            ++j;
        }
        ans=min(ans,n-(j-i));
        i++;

     }
     return ans;   
    }
};