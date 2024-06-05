class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       vector<string>ans;
        for(char i='a';i<='z';i++)
        {   bool flag=true;
         int mincount=100;
            for(int j=0;j<words.size();j++)
            {   string x=words[j];
                
                int count=0;
                for(int k=0;k<words[j].size();k++)
                {
                    if(words[j][k]==i)
                    {
                        ++count;
                    }
                }
               if(count==0)
                {
                 flag=false;
                }
             mincount=min(mincount,count);
            }
         if(flag)
         {   string x;
             x.push_back(i);
             while(mincount){
             ans.push_back(x);
                mincount --;
             }
         }
        }
        return ans;
    }
};