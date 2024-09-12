class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& qu) {
        long long n=arr.size();
       vector<vector<long long>>dp(n,vector<long long>(32,0));
       for(long long i=0;i<n;i++) 
       {
         long long j=0;
         while(j<32)
         {
            if((1<<j)&arr[i])
            {
                ++dp[i][j];
                
               
            }
            if(i>0){
            dp[i][j]+=dp[i-1][j];
            }
            cout<<dp[i][j];
             j++;
         }
       }
       vector<int>ans;
       for(long long i=0;i<qu.size();i++)
       {
          long long x=qu[i][0];
          long long y=qu[i][1];
          if(x==y)
          {
            ans.push_back(arr[x]);
            continue;
          }
          
          long long count=0;
          for(long long k=0;k<32;k++)
          {
            if((dp[y][k]-(x>0?dp[x-1][k]:0))%2)
            {
                count=count|(1<<k);
                cout<<count;
            }
          }
          ans.push_back(count);
       }
       return ans;

    }
};