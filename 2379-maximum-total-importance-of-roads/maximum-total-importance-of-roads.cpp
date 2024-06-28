class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
      //long long sum=0;
      vector<int>adj[n];
      for(int i=0;i<roads.size();i++)
      {
        adj[roads[i][0]].push_back(roads[i][1]);
         adj[roads[i][1]].push_back(roads[i][0]);
      }  
      vector<pair<int,int>>siz;
      for(int i=0;i<n;i++)
      {
        siz.push_back({adj[i].size(),i});
      }
      sort(siz.begin(),siz.end());
      unordered_map<int,int>mp;
      for(int i=n-1;i>=0;i--)
      {
        mp[siz[i].second]=i+1;
      }
      long long sum=0;
       for(int i=0;i<roads.size();i++)
      {
sum+=mp[roads[i][0]]+mp[roads[i][1]];
      }
      return sum;

    }
};