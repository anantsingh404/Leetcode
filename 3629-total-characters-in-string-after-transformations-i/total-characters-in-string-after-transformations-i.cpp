class Solution {
public:
const int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
     vector<int>mp(26,0);
     for(int i=0;i<s.size();i++)
     {
        mp[s[i]-'a']++;
     }
     for(int i=0;i<t;i++)
     {  vector<int>mp1(26,0);
        for(int j=0;j<26;j++)
        {   
            if(j>=0 && j<25)
            {
                
                mp1[j+1]=(mp1[j+1]%mod+mp[j]%mod)%mod;
                mp[j]=0;
            }
            else
            {
               
                mp1[0]=(mp1[0]%mod+mp[25]%mod)%mod;
                mp1[1]=(mp1[1]%mod+mp[25]%mod)%mod;
                 mp[25]=0;
            }
            
        }
        mp=mp1;
        
     } 
     int sum=0;
        for(int itr:mp)
        {   if(itr>0){
            sum=(sum%mod+itr%mod)%mod;
        }
        }
        return sum;

    }
};