class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       vector<int>ans;
       unordered_map<int,int>mp;
       for(int i=0;i<arr1.size();i++)
       {
        mp[arr1[i]]++;
       } 
       for(int i=0;i<arr2.size();i++)
       {
        while(mp[arr2[i]])
        {
            ans.push_back(arr2[i]);
            --mp[arr2[i]];
        }
       }
       vector<int>dp;
       for(auto itr:mp)
       {
        while(itr.second>0)
        {
            dp.push_back(itr.first);
            --itr.second;
        }
       }
       sort(dp.begin(),dp.end());
       for(int i=0;i<dp.size();i++)
       {
        ans.push_back(dp[i]);
       }
       return ans;
    }
};