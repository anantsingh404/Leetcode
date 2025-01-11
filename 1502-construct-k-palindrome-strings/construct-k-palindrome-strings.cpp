class Solution {
public:
    bool canConstruct(string s, int k) {
      unordered_map<int,int>mp;
      int count=0;
      int x=0;
      if(k>s.size())
      {
        return false;
      }
      for(int i=0;i<s.size();i++)
      {
        mp[s[i]-'a']++;
      } 
      int TEMP=0;
      bool flag=0;
      for(auto itr:mp)
      {
        if(itr.second%2)
        {
            ++count;
            x+=itr.second;
        }
        if(itr.second%2==0)
        {
            TEMP=1;
        }
    
      }
      return count<=k;
    }
};