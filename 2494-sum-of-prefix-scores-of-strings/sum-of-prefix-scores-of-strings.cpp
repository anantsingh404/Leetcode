struct trienode{
    struct trienode * arr[26];
    int count;
    trienode()
    {
        for(int i=0;i<26;i++)
        {
            arr[i]=nullptr;
        }
        count=0;
    }
};
class Solution {
private:
trienode * root;
public:

  Solution()
   {
    root=new trienode();
   }
void insert(string &s)
{
    trienode * y=root;

    for(int i=0;i<s.size();i++)
    {
        int x=s[i]-'a';
        if(y->arr[x]==NULL)
        {
            y->arr[x]=new trienode();
             y=y->arr[x];
            ++(y->count);
           
            
        }
        else
        {   y=y->arr[x];
            ++(y->count);
            
        }
        
        
       
        
    }
}
int search(string &s)
{
    int sum=0;
    trienode * y=root;
    for(int i=0;i<s.size();i++)
    {
        int x=s[i]-'a';
        if(y->arr[x]==nullptr)
        {   
            return sum;
        }
        else

        {    y=y->arr[x];
             sum+=(y->count);
            
            
           
        }
    }
    return sum;

}

    vector<int> sumPrefixScores(vector<string>& words) {
        
        for(int i=0;i<words.size();i++)
        {
            insert(words[i]);
        }
        vector<int>ans;
       for(int i=0;i<words.size();i++)
        {
        ans.push_back(search(words[i]));
        }
        return ans;
    }
};