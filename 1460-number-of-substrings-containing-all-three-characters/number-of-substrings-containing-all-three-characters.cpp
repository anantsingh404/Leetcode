class Solution {
public:
    int numberOfSubstrings(string s) {
       int n=s.size();
        int ca=-1;
        int cb=-1;
        int cc=-1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                ca=i;
            }
            else if(s[i]=='b')
            {
                cb=i;
            }
            else
            {
                cc=i;
            }
            if(i>1)
            {
                ans=ans+min(min(ca,cb),cc)+1;
            }
        }
        return ans; 
    }
};