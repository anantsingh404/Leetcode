class Solution {
public:
    int longestPalindrome(vector<string>& w) {
      unordered_map<string,int>mp;
      int n=w.size();
      for(int i=0;i<n;i++)
      {
        mp[w[i]]++;
      }
      int count=0;
      int flag=1;
      for(int i=0;i<n;i++)
      {  
        string y=w[i];
        reverse(y.begin(),y.end());
        if(w[i][0]==w[i][1])
        {
            count+=(mp[w[i]]-mp[w[i]]%2)*2;
            if(mp[w[i]]%2 && flag==1)
            {
                count+=2;
            
                flag=0;
            }
            mp[w[i]]=0;
        }
       
        else if(mp[w[i]]>0 && mp[y]>0)
        {
            count+=4;
            --mp[w[i]];
            --mp[y];
        }
      }
      return count;

    }
};