class Solution {
public:
static bool comp(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.first==p2.first)
    {
        return false;
    }
    return p1.first<p2.first;
}
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
      vector<pair<int,int>>vp;
      unordered_map<int,int>mp;
      for(int i=0;i<mapping.size();i++)
      {
        mp[i]=mapping[i];
      }
    for(int i=0;i<nums.size();i++)
    {
        string x=to_string(nums[i]);
        int ans=0;
        for(int j=0;j<x.size();j++)
        {
          int m=mp[x[j]-'0'];
          if(ans>0 && m==0)
          {
            ans=ans*10+m;
          }
          else if(ans==0 && m==0)
          {
            continue;
          }
          else {
          
          ans=ans*10+m;
          }


        }
        vp.push_back({ans,nums[i]});
        
    }
    sort(vp.begin(),vp.end(),comp);
    vector<int>res;
    for(int i=0;i<vp.size();i++)
    {
        res.push_back(vp[i].second);
    }
return res;
    }
};