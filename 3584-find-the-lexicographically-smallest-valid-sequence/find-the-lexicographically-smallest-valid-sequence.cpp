class Solution {
public:
    vector<int> validSequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> ans;
        vector<int> dp(n+1);
        bool changed = 1;
        int curIdx = m-1;
        for(int i=n-1;i>=0;i--){
            dp[i] = dp[i+1];
            if(curIdx >=0 && s1[i] == s2[curIdx]){
                curIdx--;
                dp[i]++;
            }
        }
        int j = 0;
        for(int i=0;i<n && j<m;i++){
            if(s1[i] == s2[j]){
                ans.push_back(i);
                j++;
            }else if(dp[i+1]+1 >m-j-1 && changed == 1){
                ans.push_back(i);
                changed = 0;
                j++;
            }
        }
        if(ans.size() != m){
            return {};
        }
        return ans;
    }
};