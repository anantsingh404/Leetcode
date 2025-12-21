class Solution {
public:
    int minDeletionSize(vector<string>& s) {
     int n=s.size();
     int ans=0;
     vector<string>dp(n);

     for(int j=0;j<s[0].size();j++)
     {  
          vector<string>prev=dp;
          bool temp=true;
        for(int i=0;i<n;i++)
        {  
             prev[i].push_back(s[i][j]);
             if(i>0 && prev[i]<prev[i-1])
             {
                temp=false;
             } 
        }
        if(temp==false)
        {
            ++ans;
        }
        if(temp)
        {
            dp=prev;
        }
        
       
     }
     return ans;
    }
};