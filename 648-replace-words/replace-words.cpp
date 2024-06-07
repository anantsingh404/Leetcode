class Solution {
public:
    string replaceWords(vector<string>& dict, string sen) {
       unordered_map<string,int>mp;
       for(int i=0;i<dict.size();i++) 
       {
        mp[dict[i]]++;
       }
       string temp;
       vector<string>flag;
       for(int i=0;i<sen.size();i++)
       {
        if(sen[i]==' ')
        {
            flag.push_back(temp);
            temp="";
        }
        else
        {
            temp.push_back(sen[i]);
        }
       }
       
       flag.push_back(temp);
       //cout<<flag[0]<<endl;
       temp="";
       
       for(int i=0;i<flag.size();i++)
       {
        for(auto itr:flag[i])
        {
            temp.push_back(itr);
            if(mp[temp])
            {  // cout<<mp[temp]<<endl;
                flag[i]=temp;
             
                break;
            }
        }
         temp="";
        
       }
        //cout<<flag[0]<<endl;
       temp=flag[0];
       for(int i=1;i<flag.size();i++)
       {
        temp+=" "+flag[i];
       }
       return temp;

          
    }
};