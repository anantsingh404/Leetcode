class Solution {
public:
    int maxDistance(string s, int k) {
         unordered_map<char,int>mp,mp2;
      
        int ans=0;
        for(int i=0;i<s.size();i++)
            {
                mp2[s[i]]++;
                int x=mp2['S'];
                int y=mp2['N'];
                int p=mp2['E'];
                int q=mp2['W'];
                int sum=0;
                sum+=abs(x-y);
                sum+=abs(p-q);
                int ch=k;
                if(x>0 && y>0){
                sum+=2*min(min(x,y),ch);
                ch-=min(min(x,y),ch);
                }
                if(p>0 && q>0){
                 sum+=2*min(min(p,q),ch);
                ch-=min(min(p,q),ch);
                }
                ans=max(ans,sum);
            }
            return ans;
    }
};