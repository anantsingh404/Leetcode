class Solution {
public:
    int maxScore(string s) {
      int zc=0;
      int oc=0;
      for(int i=0;i<s.size();i++)
      {
        if(s[i]=='1')
        {
            ++oc;
        }
        else
        {
            ++zc;
        }
      } 
      if(zc==s.size())
      {
        return (int)s.size()-1;
      }
        if(oc==s.size())
      {
        return (int)s.size()-1;
      }
      int o=0,z=0;
      int ans=0;
      for(int i=0;i<s.size()-1;i++)
      {
        if(s[i]=='1')
        {
            --oc;
        }
        else
        {
            ++z;
        }
        ans=max(ans,z+oc);
      } 
      return ans;
    }
};