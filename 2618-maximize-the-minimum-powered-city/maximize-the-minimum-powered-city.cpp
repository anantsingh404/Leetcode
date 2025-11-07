class Solution {
public:
    bool check(long long mid, vector<long long> dp, long long r, long long k)
    {   
        int n = dp.size();
        vector<long long>flag(n,0);
        for (int i = 0; i < n; i++)
        {   if(i>0){
            flag[i]+=flag[i-1];
        }
            
                dp[i] += flag[i];
            
            if (dp[i] < mid && k >= mid - dp[i])
            {
                long long p = mid - dp[i];
                k -= p;
                flag[i] += p;
                if (i + 2 * r + 1 < n)
                {
                    flag[i + 2 * r + 1] -= p;
                }
            }
            else if (dp[i] < mid)
            {
                return false;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& st, int r, int k) {
        
        long long ans = 0;
        int n = st.size(); 
        vector<long long> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            int x = max(0, i - r);
            int y = min(n - 1, i + r);
            dp[x] += st[i];
            if (y + 1 < n)
            {
                dp[y + 1] -= st[i];
            }
        }
        for (int i = 1; i < n; i++)
        {
            dp[i] += dp[i - 1];
        }
        ans = *min_element(dp.begin(), dp.end());
        long long mini = ans;
        long long maxi = 1e18;
        while (mini <= maxi)
        {
            long long mid = (mini + maxi) / 2;
            if (check(mid, dp, r, k)) {
                ans = mid;
                mini = mid + 1;
            }
            else
            {
                maxi = mid - 1;
            }
        }
        return ans;
    }
};
