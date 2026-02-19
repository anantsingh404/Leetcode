class Solution {
public:
    int countBinarySubstrings(string s) {
     vector<int>dp;
     int i=0;
     while(i<s.size())
     {
        int j=i;
        while(j<s.size() && s[i]==s[j])
        {
            j++;
        }
        dp.push_back(j-i);
        i=j;
     } 
     int ans=0;
     for(int i=0;i<dp.size()-1;i++)
     {
        ans+=min(dp[i],dp[i+1]);
     }  
     return ans;
    }
};