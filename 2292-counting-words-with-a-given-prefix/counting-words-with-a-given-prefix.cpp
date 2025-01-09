class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
      for(int i=0;i<words.size();i++)
      {
        int x=words[i].size();
        if(x<pref.size())
        {
            continue;
        }
        else
        {
            if(words[i].substr(0,pref.size())==pref)
            {
                ++count;
            }
        }
      } 
      return count; 
    }
};