class Solution {
public:
    long long minimumSteps(string s) {
      long long ans=0;
      long long sum=0;
      int n=s.size();
      for(int i=n-1;i>=0;i--)
      {
        if(s[i]=='0')
        {
            ++sum;
        }
        else
        {
            ans+=sum;
        }
      } 
      return ans; 
    }
};