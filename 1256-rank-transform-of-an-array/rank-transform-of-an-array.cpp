class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
      vector<int>dp=arr;
      sort(dp.begin(),dp.end());
      unordered_map<int,int>mp;
      int j=1;
      for(int i=0;i<dp.size();i++)
      {if(mp.find(dp[i])==mp.end()){

        mp[dp[i]]=j;
        j++;
      }
      }
      for(int i=0;i<arr.size();i++)
      {
        arr[i]=mp[arr[i]];
      }  
      return arr;

    }
};