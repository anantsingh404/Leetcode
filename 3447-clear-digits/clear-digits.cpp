class Solution {
public:
    string clearDigits(string s) {
        while(1){
        int flag=-1;
     for(int i=0;i<s.size();i++)
     {
        if(s[i]>=s[i]-'0' && s[i]<='9')
        {
            flag=i;
            break;
        }
     }
     if(flag==-1)
     {
        return s;
     } 
     string ans;
     for(int i=s.size()-1;i>=0;i--)
     {
        if(i!=flag && i!=flag-1)
        {
            ans=s[i]+ans;
        }
     } 
     s=ans;

        } 
    }
};