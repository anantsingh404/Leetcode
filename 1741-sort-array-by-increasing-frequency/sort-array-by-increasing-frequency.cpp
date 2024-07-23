class Solution {
public:
static bool comp(pair<int,int>p1,pair<int,int>p2){
if(p1.second==p2.second)
{
    return p1.first>p2.first;
}
return p1.second<p2.second;
}
    vector<int> frequencySort(vector<int>& nums) {
      unordered_map<int,int>m;
      for(int i=0;i<nums.size();i++)
      {
        m[nums[i]]++;
      } 
      vector<pair<int,int>>vp;
      for(auto itr:m)
      {
        vp.push_back({itr.first,itr.second});
      }
      sort(vp.begin(),vp.end(),comp); 
      vector<int>ans;
      for(int i=0;i<vp.size();i++)
      {
        int x=vp[i].second;
        while(x--)
        {
            ans.push_back(vp[i].first);
        }
      }
      return ans;
    }
};