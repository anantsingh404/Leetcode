class Solution {
public:
    int heightChecker(vector<int>& heights) {
      vector<int>dp(heights.begin(),heights.end());
      sort(dp.begin(),dp.end());
      int count=0;
      for(int i=0;i<dp.size();i++)
      {
        if(dp[i]!=heights[i])
        {
            ++count;
        }
      } 
      return count; 
    }
};