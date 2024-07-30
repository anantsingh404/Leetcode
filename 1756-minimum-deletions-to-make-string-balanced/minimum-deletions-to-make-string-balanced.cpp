class Solution {
public:
 int solve(int index,int n,string& s,bool flag,vector<vector<int>> &dp){
         if(index==n)return 0;
        int mini = 1e9;
        if(dp[index][flag]!=-1)return dp[index][flag];
        //include 
    if(s[index]=='a' && flag==false){
           int element = solve(index+1,n,s,flag,dp);
           mini = min(mini,element);
       }
        else if(s[index]=='b'){
            int element = solve(index+1,n,s,true,dp);
            mini = min(mini,element);
        } 
         //not include
        
        int element = 1+solve(index+1,n,s,flag,dp);
        mini = min(mini,element);
        return dp[index][flag] = mini;
    }
    int minimumDeletions(string s) {
        int n = s.size();
     vector<vector<int>> dp(n,vector<int>(2,-1));
        bool flag = false;
        return solve(0,n,s,flag,dp);
    }
};