class Solution {
public:
    string largestGoodInteger(string num) {
       string ans="";
       for(int i=0;i<num.size()-2;i++){
        string x=num.substr(i,3);
        if(x[0]==x[1] && x[1]==x[2])
        {
            if(ans<x)
            {
                ans=x;
            }
        }
       }
       return ans; 
    }
};