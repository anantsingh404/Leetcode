class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
      map<pair<int,int>,int>mp;
      int n=d.size();
      for(int i=0;i<d.size();i++)
      {
        int x=min(d[i][0],d[i][1]);
        int y=max(d[i][0],d[i][1]);
        mp[{x,y}]++;
      }
      int ans=0;
      for(auto itr:mp)
      {
        ans+=((itr.second)*(itr.second-1))/2;
      }
      return ans;

    }
};