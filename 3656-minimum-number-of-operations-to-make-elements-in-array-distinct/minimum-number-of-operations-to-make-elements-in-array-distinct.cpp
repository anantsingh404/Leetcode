class Solution {
public:
    int minimumOperations(vector<int>& nums) {
  unordered_map<int,int>mp;
      int count=0;
      int n=nums.size();
      int idx=-1;
      for(int i=n-1;i>=0;i--)
      {
        if(mp[nums[i]]>0)
        {
            idx=i;
            break;
        }
        else
        {
            mp[nums[i]]++;
        }
      }
      if(idx==-1)
      {
        return 0;
      }
      int x=(idx+1)/3;
      if((idx+1)%3)
      {
        ++x;
      }
      return x;
        
    }
};