class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
     vector<pair<int,int>>vp;
     int n=items.size();
     for(int i=0;i<items.size();i++)
     {
        vp.push_back({items[i][0],items[i][1]});
     }
     sort(vp.begin(),vp.end());
     vector<int>dp(items.size(),0);
     dp[0]=vp[0].second;
     for(int i=1;i<vp.size();i++)
     {
        dp[i]=max(dp[i-1],vp[i].second);
     }
     vector<int>ans;
     for(int i=0;i<queries.size();i++)
     {
        int x=queries[i];
        ++x;
        pair<int,int>p={x,0};
        auto itr=lower_bound(vp.begin(),vp.end(),p);
        if(itr==vp.end())
        {
            ans.push_back(dp[n-1]);
        }
        else if(itr==vp.begin())
        {
            ans.push_back(0);
        }
        else
        {
            --itr;
            int y=itr-vp.begin();
            ans.push_back(dp[y]);
        }
     }
     return ans;


    }
};