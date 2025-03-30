class Solution {
public:
    vector<int> partitionLabels(string s) {
      unordered_map<int,pair<int,int>>mp;
      for(int i=0;i<s.size();i++)
      {
        int x=s[i]-'a';
        if(mp.find(x)==mp.end())
        {
            mp[x]={i,i};
        }
        else
        {
            mp[x].second=i;
        }
      }
      vector<pair<int,int>>vp;
      for(auto itr:mp)
      {
        vp.push_back({itr.second.first,itr.second.second});
      }
      sort(vp.begin(),vp.end());
      vector<pair<int,int>>ans;
      int start=vp[0].first;
      int end=vp[0].second;
      for(int i=1;i<vp.size();i++)
      {
       if(vp[i].first<end)
       {
        end=max(end,vp[i].second);
       }
       else
       {
        ans.push_back({start,end});
        start=vp[i].first;
        end=vp[i].second;
       }
      }
       ans.push_back({start,end});
        vector<int>res;
        for(int i=0;i<ans.size();i++)
        {
            res.push_back(ans[i].second-ans[i].first+1);
        }
        return res;  
    }
};