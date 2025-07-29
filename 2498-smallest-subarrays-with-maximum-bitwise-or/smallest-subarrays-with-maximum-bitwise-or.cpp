class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
      vector<int>ans;
      int  n=nums.size();
      unordered_map<int,int>mp;
      for(int i=n-1;i>=0;i--)
      {  
        for(int j=0;j<32;j++)
        {
            if((1<<j)&nums[i])
            {
                mp[j+1]=i;
            }
        }
        int maxi=i;
        for(auto itr:mp)
        {
            maxi=max(maxi,itr.second);
        }
        ans.push_back(maxi-i+1);
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};