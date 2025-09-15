class Solution {
public:
    int canBeTypedWords(string text, string bl) {
     unordered_map<int,int>mp;
     for(int i=0;i<bl.size();i++)
     {
        mp[bl[i]-'a']++;
     }
     int count=0;
     int tl=0;
     int i=0;
     int j=0;
     while(i<text.size())
     {
        
        if(text[i]==' ')
        {
            i++;
            continue;
        }
        int j=i;
        int temp=1;
        while(j<text.size() && text[j]!=' ')
        {
            if(mp[text[j]-'a']>0 && temp)
            {
                ++count;
                temp=0;
                
            }
            j++;
         
        }
           ++tl;
        i=j+1;
     }
     return tl-count;


    }
};