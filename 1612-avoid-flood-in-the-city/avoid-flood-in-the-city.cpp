class Solution {
public:
    vector<int> avoidFlood(vector<int>& r) {
     int n=r.size();
     vector<int>ans(n,1);
     set<int>st;
     unordered_map<int,int>mp;
     for(int i=0;i<n;i++)
     {
        if(r[i]==0)
        {
            st.insert(i);

        }
        else if(mp[r[i]]<1)
        {
            mp[r[i]]=i+1;
            ans[i]=-1;
        }
        else if(mp[r[i]]>0)
        {
          auto x=st.lower_bound(mp[r[i]]);
          if(x==st.end())
          {
            vector<int>temp;
            return temp;
          }else
          {
            ans[*x]=r[i];
            mp[r[i]]=i+1;

            ans[i]=-1;
            st.erase(x);
          }

        }
        else
        {
            vector<int>temp;
            return temp;
        }


     }
     for(int i=0;i<n;i++){
        if(ans[i]==0)
        {
            ans[i]=1;
        }
     }
     return ans;

    }
};