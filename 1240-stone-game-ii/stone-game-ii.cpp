class Solution {
    int n;
    int dp[102][102][2];
private:
    int f(int ind, int M, int isAlice, vector<int>& piles){
        if(ind>=n){
            return 0;
        }
        if(dp[ind][M][isAlice]!=-1) return dp[ind][M][isAlice];
        int ans = isAlice ? INT_MIN : INT_MAX;
        int sum = 0;
        for(int x=1; x<=min(2*M,n-ind); x++){
            sum += piles[ind+x-1];
            if(isAlice){ // maximise stones in Alice's turn
                ans = max(ans, sum + f(ind+x, max(M,x), 1-isAlice, piles));
            }
            else{ // minimise stones in Bob's turn
                ans = min(ans, f(ind+x, max(M,x), 1-isAlice, piles));
            }
        }
        return dp[ind][M][isAlice] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp,-1,sizeof(dp));
        return f(0,1,1,piles);
    }
};