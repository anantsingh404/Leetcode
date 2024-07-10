class Solution {
public:
    int minOperations(vector<string>& logs) {
     int parent=0;
     for(int i=0;i<logs.size();i++)
     {   if(logs[i]=="../")
        {
            --parent;
            parent=max(0,parent);
        }
        else if(logs[i]!="./")
        {
            ++parent;
        }
       
     }
     return max(parent,0);   
    }
};