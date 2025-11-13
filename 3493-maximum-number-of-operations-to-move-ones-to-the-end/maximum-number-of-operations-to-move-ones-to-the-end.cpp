class Solution {
public:
    int maxOperations(string s) {
     int n=s.size();
     vector<int>dp;
     int count=0;
     int ans=0;
     int i=n-1;
     while(i>=0)
     {
        if(s[i]=='0')
        {
            int j=i;
            while(j>=0 && s[j]==s[i])
            {
                j--;
            }
            i=j;
            ++count;
        }
        else
        {
            ans+=count;
            --i;

        }
     }
     return ans;  
    }
};