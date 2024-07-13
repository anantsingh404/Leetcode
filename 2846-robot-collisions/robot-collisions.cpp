class Solution {
public:
unordered_map<int,int>mp;
static bool cmp(pair<int,int>x,pair<int,int>y)
{
    return x.first<y.first;
}
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
      stack<pair<int,pair<int,int>>>st;
      vector<pair<int,pair<int,int>>>vp;
       int n=positions.size();
       
      for(int i=0;i<n;i++)
      {
        vp.push_back({{positions[i]},{healths[i],directions[i]}});
        mp[positions[i]]=i;
      }
      sort(vp.begin(),vp.end());
     
      vector<bool>dp(n,true);
      int i=0;
      while(i<n)
      {
        if(st.empty())
        {
            st.push(vp[i]);
            i++;
            continue;
        }
            int x=st.top().first;
            int y=st.top().second.first;
            int z=st.top().second.second;
            int p=vp[i].first;
            int q=vp[i].second.first;
            int r=vp[i].second.second;
            if(z=='R' && r=='L')
            {
           
            if(y>q)
            {
                --st.top().second.first;
                i++;
            }
            else if(y<q)
            {
                --vp[i].second.first;
                st.pop();
            }
            else
            {
                st.pop();
                i++;
            }
        }
      
        else
        {
            st.push(vp[i]);
            i++;
        }
      }

vector<pair<int,int>>ans;
while(!st.empty())
{
    ans.push_back({mp[st.top().first],st.top().second.first});
    st.pop();
}
sort(ans.begin(),ans.end(),cmp);
//reverse(ans.begin(),ans.end());
vector<int>res;
for(int i=0;i<ans.size();i++)
{
    res.push_back(ans[i].second);
}
return res;
    }
};