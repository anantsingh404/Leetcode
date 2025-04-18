class Solution {
public:
    string countAndSay(int n) {
           if(n==1)
        {
            return "1";
        }
        string prev=countAndSay(n-1);
        string res="";
        for(int i=0;i<prev.size();)
        {
            char cd=prev[i];
            int count=0;
            while(i<prev.size() && prev[i]==cd)
            {
                ++i;
                ++count;
            }
            res+=to_string(count);
            res.push_back(cd);
        }
        return res;
    }
};