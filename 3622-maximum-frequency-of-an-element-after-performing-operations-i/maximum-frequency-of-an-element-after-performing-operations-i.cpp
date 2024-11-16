class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int no) {
         int n=nums.size();
        
        vector<pair<int,int>>vp;
         set<int>s;
        unordered_map<int,int>mp;
        int co=0;
        int mf=0;
        int ac=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
            {  
                mp[nums[i]]++;
                int x=nums[i]-k;
                int y=nums[i]+k+1;
                
                vp.push_back({x,1});
                vp.push_back({y,-1});
            }
         for(auto itr:mp)
            {
                s.insert(itr.first);
            }
        for(int i=0;i<vp.size();i++)
            {
                s.insert(vp[i].first);
            }
        
        sort(vp.begin(),vp.end());
        int i=0;
        for(auto temp:s)
            {
                while(i<vp.size() && vp[i].first<=temp)
                    {
                        co=co+vp[i].second;
                        ++i;
                    }
                ac=mp[temp];
                 
                int fla=ac+min(no,co-ac);
                mf=max(mf,fla);
            }
        return mf;
      
    }
};