class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
      vector<int>left(n,0);
      vector<int>right(n,0); left[0]=1;
      right[n-1]=1;
      for(int i=1;i<n;i++)
      {if(nums[i]>nums[i-1])
      {
        left[i]=left[i-1]+1;
      } 
      else
      {
        left[i]=1;
      }
      }
       for(int i=n-2;i>=0;i--)
      {if(nums[i]<nums[i+1])
      {
        right[i]=right[i+1]+1;
      } 
      else
      {
        right[i]=1;
      }
      }int ans=0;
      for(int i=1;i<n;i++)
      {
        ans=max(ans,min(left[i-1],right[i]));
      }
      return ans;
    }
};