class Solution {
public:
    int longestSubarray(vector<int>& s) {
        vector<pair<int,int>>vp;
        int ans=0;
        
        int n=s.size();
        bool temp=true;
        for(int i=0;i<n;i++)
        {
            if(s[i]==0)
            {
                temp=false;
            }
        }
        if(temp)
        {
            return s.size()-1;
        }
        int i=0;
        while(i<n)
        {
            int j=i;
            while(j<n && s[j]==s[i])
            {
                ++j;
            }
            vp.push_back({s[i],j-i});
            i=j;
        }
        for(int i=1;i<vp.size()-1;i++)
        {
            if(vp[i].first==0 &&vp[i].second==1)
            {
                ans=max(ans,vp[i-1].second+vp[i+1].second);
            }
            if(vp[i].first==1)
            {
                ans=max(ans,vp[i].second);
            }
        }
        if(vp[0].first==1)
        {
            ans=max(ans,vp[0].second);
        }
        if(vp[vp.size()-1].first==1)
        {
            ans=max(ans,vp[vp.size()-1].second);
        }
        return ans;
    }
};