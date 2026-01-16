class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
     unordered_map<int,int>mp;
     sort(h.begin(),h.end());
     sort(v.begin(),v.end());   
     h.insert(h.begin(),1);
     h.push_back(m);
     v.insert(v.begin(),1);
     v.push_back(n);
     for(int i=0;i<h.size();i++){
        for(int j=i+1;j<h.size();j++)
        {
            mp[h[j]-h[i]]++;
        }
     }
     int ans=-1;
     for(int i=0;i<v.size();i++)
     {for(int j=i+1;j<v.size();j++)
     {
        int diff=v[j]-v[i];
        if(mp.find(diff)!=mp.end() && diff>ans)
        {
              ans=diff;
        }
     }
     }if(ans==-1)
     {
        return -1;
     }
     const int mod=1e9+7;
     return (int)((1ll*ans*ans)%mod);
    }
};