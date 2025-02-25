class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod=1e9+7;
     unordered_map<int,int>mp;
     int odd=0;
     int count=0;
     for(int i=0;i<arr.size();i++)
     {
      if(arr[i]%2)
      {
        ++odd;
      }
      if(odd%2)
      {
    count=(count+1)%mod;
      }
      if(odd%2)
      {
      count=(count+mp[0])%mod;
      }
      else if(odd>0)
      {
        count=(count+mp[1])%mod;
      }
      mp[odd%2]++;
     }
     return count;
    }
};