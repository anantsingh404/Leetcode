class Solution {
public:
    int minimumPushes(string word) {
     unordered_map<int,int>mp;
     for(int i=0;i<word.size();i++)
     {
        mp[word[i]-'a']++;
     } 
     vector<int>ans;
     for(auto itr:mp)
     {
        ans.push_back(itr.second);
     }
     int res=0;
     sort(ans.begin(),ans.end());
     int count=1;
      int temp=1;
     for(int i=ans.size()-1;i>=0;i--){
            res+=count*ans[i];
            ++temp;
            if(temp>8)
            {
                temp=1;
                ++count;
            }
            
     } 
     return res; 
    }
};