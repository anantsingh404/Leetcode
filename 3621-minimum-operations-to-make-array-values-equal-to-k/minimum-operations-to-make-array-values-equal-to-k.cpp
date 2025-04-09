class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
      unordered_map<int,int>mp;
          for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int,int>>vp;
        for(auto itr:mp)
            {
                vp.push_back({itr.first,itr.second});
            }
        sort(vp.begin(),vp.end());
        bool ans=true;
        if(vp.size()==1)
        {
            if(vp[0].first==k)
            {
                return 0;
            }
        }
        if(vp[0].first<k)
        {
            return -1;
        }
       
        int sum=0;
        for(int i=1;i<vp.size();i++)
            {
                ++sum;
            }
        if(vp[0].first>k)
        {
            ++sum;
        }
        return sum;
    }
};