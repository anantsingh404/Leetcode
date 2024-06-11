class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        unordered_map<char,int>mp;
        //int n=words.size();
        int even=0;
        int pair=0;
        vector<int>dp;
        for(int i=0;i<words.size();i++)
        {   
            dp.push_back(words[i].size());
            for(auto x:words[i])
            {
                mp[x]++;
            }
        }
        int n=words.size();
        int oddcount=0;
        for(auto itr:mp)
        {
            if(itr.second%2)
            {
                ++oddcount;
                pair+=itr.second/2;
            }
            else 
            {
                pair+=itr.second/2;
            }
        }
        int count=0;
        sort(dp.begin(),dp.end());
        for(int i=0;i<dp.size();i++)
        {
            if(dp[i]%2 && oddcount && pair>=dp[i]/2)
            {
                ++count;
                --oddcount;
                pair-=dp[i]/2;

            }
            else if(dp[i]%2 && pair>dp[i]/2)
            {
                ++count;
                ++oddcount;
                --pair;
                pair-=(dp[i]/2);
            }
            else if(dp[i]%2 && dp[i]==1 && oddcount>=1)
            {
                ++count;
                --oddcount;
            }
            else if(dp[i]%2==0 && pair>=dp[i]/2)
            {
                ++count;
                pair-=dp[i]/2;
            }
        }
        return count;
        
    }
};