class Solution {
public:
    int findLucky(vector<int>& arr) {
      unordered_map<int,int>mp;
      for(int i=0;i<arr.size();i++)
      {
        mp[arr[i]]++;
      } 
      int ans=-1;
      for(auto itr:mp)
      {
          if(itr.second==itr.first)
          {
            ans=max(ans,itr.first);
          }
      }
      return ans; 
    }
};