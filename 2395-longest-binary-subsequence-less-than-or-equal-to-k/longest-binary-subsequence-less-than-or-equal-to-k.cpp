#define ll long long
class Solution {
public:

    int longestSubsequence(string s, int k) {
        int n=s.size();
        int ans=0;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                ++ans;
            }
        }
        reverse(s.begin(),s.end());
        for(ll i=0;i<n;i++)
        {
         if(s[i]=='1')
         {
            if(i<=31 && ((1ll<<i)+sum)<=k)
            {
                ++ans;
                sum+=(1ll<<i);
            }
         }
        }
        return ans;
        
    }
};