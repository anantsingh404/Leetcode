class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
     int count=0;
     for(int i=0;i<bank[0].size();i++)
     {
        count+=bank[0][i]-'0';
    } 
     int ans=0;
     for(int i=1;i<bank.size();i++)
     {  int flag=0;
        for(int j=0;j<bank[0].size();j++)
        {
            flag+=bank[i][j]-'0';
        }
        ans+=flag*count;
        if(flag)
        {
            count=flag;
        }
     }
     return ans;  
    }
};