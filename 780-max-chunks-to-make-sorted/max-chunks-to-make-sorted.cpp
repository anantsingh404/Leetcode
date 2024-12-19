class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
      vector<pair<int,int>>vp;
      unordered_map<int,int>mp;
      int n=arr.size();
      
      for(int i=0;i<n;i++)
      {
         vp.push_back({i,arr[i]});
      }
      sort(vp.begin(),vp.end());
      int start=vp[0].first;
      int end=vp[0].second;
      int count=0;
      for(int i=1;i<n;i++)
      {
        if(vp[i].first<=end)
        {
            end=max(end,vp[i].second);
        }
        else
        {
            ++count;
            start=vp[i].first;
            end=vp[i].second;
        }
      }
      ++count; 
      return count; 
    }
};