class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
      int ans=0;
      for(int i=0;i<op.size();i++)
      {
        if(op[i]=="++X" || op[i]=="X++"){
            ++ans;
        }if(op[i]=="--X" || op[i]=="X--"){
            --ans;
        }
      }
      return ans;  
    }
};