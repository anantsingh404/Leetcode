class Solution {
public:
   
    string sortVowels(string s) {
        
        int n=s.size();
        vector<char>ans;
        for(int i=0;i<n;i++)
        {
            char a=s[i];
             if((a=='a' || a=='e' || a=='i' || a=='o' || a=='u'|| a=='A' || a=='E' || a=='I' || a=='O' || a=='U'))
             {
                 ans.push_back(a);
             }
        }
        sort(ans.begin(),ans.end());
        int j=0;
        for(int i=0;i<n;i++)
        {
            char a=s[i];
             if((a=='a' || a=='e' || a=='i' || a=='o' || a=='u'|| a=='A' || a=='E' || a=='I' || a=='O' || a=='U'))
             {
                 s[i]=ans[j];
                 ++j;
             }
        }
        return s;
        
    }
};