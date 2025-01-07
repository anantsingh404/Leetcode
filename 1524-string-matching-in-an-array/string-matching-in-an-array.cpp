class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
      unordered_map<string,int>mp;
      vector<string>ans;
      for(int i=0;i<words.size();i++)
      {  
       
        for(int j=0;j<words[i].size();j++)
        { string x;
         for(int k=j;k<words[i].size();k++)
         {
            x.push_back(words[i][k]);
              mp[x]++;
         }

       
        }
      }
      for(int i=0;i<words.size();i++)
      {
        --mp[words[i]];
        if(mp[words[i]]>0)
        {
            ans.push_back(words[i]);
        }
        mp[words[i]]++;
      }
      for(auto itr:mp)
      {
        cout<<itr.first<<" "<<itr.second<<endl;
      }
      return ans;  
    }
};