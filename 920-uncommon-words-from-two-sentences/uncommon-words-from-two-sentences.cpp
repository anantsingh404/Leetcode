class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
      unordered_map<string,int>mp;
      string temp="";
      for(char itr:s1)
      {
        if(itr==' ')
        {
            mp[temp]++;
            temp="";
        }
        else
        {
            temp.push_back(itr);
        }
      }
      if(temp.size()>0)
      {
        mp[temp]++;
      } 
      temp="";
      for(char itr:s2)
      {
        if(itr==' ')
        {
            mp[temp]++;
            temp="";
        }
        else
        {
            temp.push_back(itr);
        }
      }
      vector<string>ans;
      if(temp.size()>0)
      {
        mp[temp]++;
      } 
      for(auto itr:mp)
      {
        if(itr.second==1)
        {
            ans.push_back(itr.first);
        }
      }
      return ans;

    }
};