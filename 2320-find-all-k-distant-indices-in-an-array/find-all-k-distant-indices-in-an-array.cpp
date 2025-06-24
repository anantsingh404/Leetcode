class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        int n=nums.size();
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]==key)
        {
            ans.push_back(i);
            continue;
        }
        for(int j=max(0,i-k);j<n;j++)
        {
            if(nums[j]==key && abs(j-i)<=k)
            {
                ans.push_back(i);
                break;
            }
        }
      } 
      return ans; 
    }
};