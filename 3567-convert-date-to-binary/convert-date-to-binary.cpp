class Solution {
public:
    string convertDateToBinary(string date) {
       int x=0;
       string ans;
       for(int i=0;i<date.size();i++)
       {
        if(date[i]!='-')
        {
            x=x*10+(date[i]-'0');
        }
        else
        {
            int j=0;
            string y;
            while((1<<j)<=x)
            {
                if((1<<j)&(x))
                {
                    y.push_back('1');
                }
                else
                {
                    y.push_back('0');
                }
                j++;
            }
            reverse(y.begin(),y.end());
            ans+=y;
            ans.push_back('-');
            x=0;
        }
       }
        int j=0;
        string y;
            while((1<<j)<=x)
            {
                if((1<<j)&(x))
                {
                y.push_back('1');
                }
                else
                {
                    y.push_back('0');
                }
                j++;
            }
            reverse(y.begin(),y.end());

            return ans+=y; 

    }
};