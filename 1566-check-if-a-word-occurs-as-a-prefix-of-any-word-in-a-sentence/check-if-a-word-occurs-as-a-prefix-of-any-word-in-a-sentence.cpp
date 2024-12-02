class Solution {
public:
    int isPrefixOfWord(string sen, string sw) {
      unordered_map<string,int>mp;
      int k=0;
      int i=1;
      while(k<sen.size())
      {
        int j=k;
        string temp;
        while(j<sen.size() && sen[j]!=' ')
        {
            temp.push_back(sen[j]);
            j++;
            if(mp.find(temp)==mp.end())
        {
            mp[temp]=i;
        }
        }
         k=j+1;
        ++i;
      } 
if(mp.find(sw)!=mp.end())
        {
            return mp[sw];
        }
        return -1;
    }
};