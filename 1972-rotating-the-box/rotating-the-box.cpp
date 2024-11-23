class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
      int n=box.size();
      int m=box[0].size();
      vector<vector<char>>dp(n,vector<char>(m,'.'));
      for(int i=0;i<n;i++)
      {
        int k=m-1;
        for(int j=m-1;j>=0;j--)
        {
          if(box[i][j]=='*')
          {  dp[i][j]='*';
            k=j-1;
          } 
          if(box[i][j]=='#') 
          {
            dp[i][k--]='#';
          }

        }
      }
      
      vector<vector<char>> rotatedBox(m, vector<char>(n));
        for (int i = 0; i <n ; i++) {
            for (int j = 0; j < m; j++) {
                rotatedBox[j][n - 1 - i] = dp[i][j];
            }
        }
      
     return rotatedBox;
         
    }
};