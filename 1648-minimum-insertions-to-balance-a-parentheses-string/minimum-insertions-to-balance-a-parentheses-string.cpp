class Solution {
public:
    int minInsertions(string s) {
     int n=s.length();
     int ans=0;
     int count=0;
     for(int i=0;i<n;)
     {
        if(s[i]=='(')
        {
            ++count;i++;
        }
        else if(count>0 && s[i]==')' && i+1<n && s[i+1]==')')
        {
            --count;
            i+=2;
        }
          else if(count==0 && s[i]==')' && i+1<n && s[i+1]==')')
        {
            ++ans;

            i+=2;
        } else if(count>0 && s[i]==')')
        {
            ++ans;
            --count;
            
            i++;
        }
         else if(count==0 && s[i]==')')
        {
            ans+=2;
            
            i++;
        }
     }return ans+=count*2;   
    }

};