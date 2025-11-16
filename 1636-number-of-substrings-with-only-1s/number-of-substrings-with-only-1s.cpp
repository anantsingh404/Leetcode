class Solution {
public:
    int numSub(string s) {
     int mod=1e9+7;
     int i=0;
     long long ans=0;
     while(i<s.size())
     {
       
        if(s[i]=='0')
        {
            i++;
        }
        else
        {
        int j=i;
        while(j<s.size() && s[i]==s[j])
        {
            j++;
        }
        
        ans=(ans+(1ll*(j-i)*(j-i+1))/2)%mod;
        i=j;
        }  
     } 
     return (int)ans;  
    }
};