class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
    vector<pair<int,int>>vp;
    int n=nums.size();
    for(int i=0;i<nums.size();i++)
    {
        vp.push_back({nums[i]-k,nums[i]+k});
    }    
    sort(vp.begin(),vp.end());
    int mini=vp[0].first;
    int count=1;
    for(int i=1;i<n;i++)
    {   if(vp[i].second>mini)
    {
        int next=max(mini+1,vp[i].first);
        mini=next;
        ++count;

        }
    }
    return count;
    }
};