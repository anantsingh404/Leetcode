class Solution {
public:
    int maximumLength(string s) {
      unordered_map<string,int>mp;
      for(int i=0;i<s.size();i++)
      {
                int j=i;
                while(j<s.size() && s[i]==s[j])
               {     mp[s.substr(i,j-i+1)]++;
                    j++;
                }
      }
      int an=-1;
      for(auto itr:mp)
      {
        if(itr.second>=3)
        {
            an=max(an,(int)itr.first.size());
        }
      }
       return an;
    }
};