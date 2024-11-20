class Solution {
public:
    int takeCharacters(string s, int k) {
       int ans=INT_MAX;
       int n=s.size();
       int a=0;
       int b=0;
       int c=0;
       int i=0;
       while(i<n)
       {
        if(s[i]=='a')
        {
            ++a;
        }
        else if(s[i]=='b')
        {
            ++b;
        }
        else
        {
            ++c;
        }
        if(a>=k && b>=k && c>=k)
        {
            ans=i+1;
            break;
        }
        i++;
       } 
       if(ans==INT_MAX)
       {
        return -1;
       }
       int j=n-1;
       while(i>=0)
       {
        if(s[i]=='a')
        {
            --a;
        }
         if(s[i]=='b')
        {
            --b;
        }
        if(s[i]=='c')
        {
            --c;
        }
        
        while(j>=i && (a<k || b<k || c<k ))
        {
            if(s[j]=='a')
        {
            ++a;
        }
         if(s[j]=='b')
        {
            ++b;
        }
        if(s[j]=='c')
        {
            ++c;
        }
        --j;
        }
        cout<<i<<" "<<j<<endl;
        ans=min(ans,i+(n-j-1));
        --i;
       }
       return ans;
    }
};