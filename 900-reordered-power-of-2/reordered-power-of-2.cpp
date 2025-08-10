class Solution {
public:
    bool reorderedPowerOf2(int n) {
      long long ans=1;
      if(n==1)
      {
        return true;
      }
      while(ans<=1e10)
      {
        ans*=2;
        unordered_map<int,int>mp1,mp2;
        string x=to_string(ans);
        string y=to_string(n);
        for(int i=0;i<x.size();i++)
        {
            mp1[x[i]-'0']++;
        }
         for(int i=0;i<y.size();i++)
        {
            mp2[y[i]-'0']++;
        }
        if(mp1==mp2)
        {
            return true;
        }
      }
      return false;  
    }
};