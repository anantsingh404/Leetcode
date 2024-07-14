class Solution {
public:
    int minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
     int hp=1;
     int vpp=1;
     int count=0;
     vector<pair<int,char>>vp;
     for(int i=0;i<hc.size();i++)
     {
        vp.push_back({hc[i],'H'});
     }
     for(int i=0;i<vc.size();i++)
     {
        vp.push_back({vc[i],'V'});
     }
     sort(vp.begin(),vp.end());
     for(int i=vp.size()-1;i>=0;i--)
     {
        if(vp[i].second=='H')
        {
            count+=vp[i].first*vpp;
            ++hp;

        }
        else if(vp[i].second=='V')
        {
             count+=vp[i].first*hp;
              ++vpp;
        }
     }
return count;
    }
};