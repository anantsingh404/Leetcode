class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
       vector<pair<int,int>>temp;
       for(int i=0;i<nums.size();i++)
       {
        for(int j=0;j<nums[i].size();j++)
        {
            temp.push_back({nums[i][j],i});
        }
       } 
       sort(temp.begin(),temp.end());
       int count=0;
       int ans=INT_MAX;
       int j=0;
       vector<int>vis(nums.size(),0);
       pair<int,int>p;
       for(int i=0;i<temp.size();i++)
       {
        int x=temp[i].first;
        int y=temp[i].second;
        vis[y]++;
        if(vis[y]==1)
        {
            ++count;
        }
        while(count==nums.size())
        {
            int z=temp[i].first-temp[j].first;
            if(z<ans)
            {
                p.first=temp[j].first;
                p.second=temp[i].first;
                ans=z;
            }
            vis[temp[j].second]--;
            if(vis[temp[j].second]==0)
            {
                --count;
            }
            j++;

        }
       }
         return {p.first,p.second}; 
       
    }
};