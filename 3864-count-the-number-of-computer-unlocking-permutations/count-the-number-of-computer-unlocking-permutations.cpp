class Solution {
public:
    int countPermutations(vector<int>& com) {int p=com[0];
     sort(com.begin(),com.end());
     long long ans=1;
     int n=com.size();
     const int mod=1e9+7;
     if(com[0]==com[1] || p!=com[0])
     {
        return 0;
     } if(n==2)
     {
        return 1;
     }
     for(int i=1;i<=n-1;i++)
     {
        ans=1ll*ans*i%mod;
     }
     return (int)ans;
    }
};