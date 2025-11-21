class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
       vector<vector<int>>left(n,vector<int>(26,0));
       vector<vector<int>>right(n,vector<int>(26,0));  
      for(int i=0;i<s.size();i++)
      {
        int x=s[i]-'a';
        if(i>0){
       for(int j=0;j<26;j++)
       {
        left[i][j]=left[i-1][j];
       }
        }
        ++left[i][x];
      }
      for(int i=n-1;i>=0;i--)
      {
        int x=s[i]-'a';
        if(i<n-1){
       for(int j=0;j<26;j++)
       {
        right[i][j]=right[i+1][j];
       }
        }
        ++right[i][x];
      }
      
       unordered_set<string> seen;
        int ans = 0;

        for(int i = 1; i < n - 1; i++) {
            for(int j = 0; j < 26; j++) {
                if(left[i-1][j] > 0 && right[i+1][j] > 0) {

                    string key;
                    key.push_back(char(j + 'a'));
                    key.push_back(s[i]);
                    key.push_back(char(j + 'a'));

                    if(seen.insert(key).second) {
                        ans++;
                    }
                }
            }
        }

      return ans;
    }
};