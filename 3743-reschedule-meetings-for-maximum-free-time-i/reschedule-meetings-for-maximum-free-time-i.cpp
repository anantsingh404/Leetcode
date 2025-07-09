class Solution {
public:
    int maxFreeTime(int et, int k, vector<int>& start, vector<int>& end) {
        vector<pair<int,int>>vp;
        for(int i=0;i<start.size();i++)
        {
            vp.push_back({start[i],end[i]});
        }
        sort(vp.begin(),vp.end());
        int sum=0;
        for(int i=0;i<vp.size();i++)
        {
            sum+=(vp[i].second-vp[i].first);
        }
        
        vector<int>temp;
        int n=start.size();
        if(n<=k)
        {
            return et-sum;
        }
        int mini=0;
            temp.push_back(vp[0].first);
            mini=max(mini,vp[0].second);
        
        for(int i=1;i<n;i++)
        {
           temp.push_back(vp[i].first-mini);
           mini=max(mini,vp[i].second);
        }
        if(et>mini)
        {
            temp.push_back(et-mini);
        }
        int ans=0;
        int j=0;
        int res=0;
        for(int i=0;i<temp.size();i++)
        {
            ans+=temp[i];
            if(i>=k+1)
            {
                ans-=temp[j++];
            }
            res=max(res,ans);
        }
        return res;
    }
};