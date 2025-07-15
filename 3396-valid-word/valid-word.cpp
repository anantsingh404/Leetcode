class Solution {
public:
    bool isValid(string word) 
    {
       bool ans=true;
       bool cons=false;
       bool vo=false;
       for(int i=0;i<word.size();i++)
       {
        if(word[i]=='$' || word[i]=='#' || word[i]=='@')
        {
            return false;
        }
        if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
        {
            vo=true;
        }
        if(word[i]!='a' && word[i]!='e' && word[i]!='i' && word[i]!='o' && word[i]!='u' && word[i]>='a' && word[i]<='z')
        {
            cons=true;
        }
        if(word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U')
        {
            vo=true;
        }
        if(word[i]!='A' && word[i]!='E' && word[i]!='I' && word[i]!='O' && word[i]!='U' && word[i]>='A' && word[i]<='Z')
        {
            cons=true;
        }
       } 
       ans=ans&vo;
       ans=ans&cons;
       return ans && word.size()>=3;
    }
};