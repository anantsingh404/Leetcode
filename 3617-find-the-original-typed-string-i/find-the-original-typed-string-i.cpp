class Solution {
public:
    int possibleStringCount(string word) {
     unordered_map<int,int>mp;
     int ans=0;
     int i=0;
     
     while(i<word.size())
     {
        int j=i;
        while(j<word.size() && word[i]==word[j])
        {
          ++j;
        }
       
        ans+=(j-i-1);
         i=j;
     }
     ++ans;
     return ans;  
    }
};