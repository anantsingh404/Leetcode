class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
       unordered_map<int,int>mp1;
       unordered_map<int,int>mp2; 
       for(int i=0;i<nums1.size();i++)
       {
        mp1[nums1[i][0]]=nums1[i][1];
       }
        for(int i=0;i<nums2.size();i++)
       {
        mp2[nums2[i][0]]=nums2[i][1];
       }
       vector<vector<int>>ans;
       for(auto itr:mp1)
       {
        int x=itr.second;
        if(mp2[itr.first]>0)
        {
            ans.push_back({itr.first,x+mp2[itr.first]});
        }
        else
        {
            ans.push_back({itr.first,x});
        }
       }
        for(auto itr:mp2)
       {
        int x=itr.second;
        if(mp1[itr.first]<1)
        {
            ans.push_back({itr.first,x});
        }
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};