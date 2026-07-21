class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
     int ma=0;
     vector<pair<int,int>>vp;   
     int i=0;
     int n=s.size();
     int count=0;
     while(i<n)
     {
         int j=i;
         while(j<n && s[j]==s[i])
         {  if(s[j]=='1')
         {
            ++count;
         }
            j++;
         }
         vp.push_back({s[i]-'0',j-i});
         i=j;

     }
     int maxi=0;
     for(int i=1;i<vp.size()-1;i++)
     {
        if(vp[i].first==1)
        {
            maxi=max(maxi,vp[i-1].second+vp[i+1].second);
        }
     }
     return count+maxi;
     
    }
};