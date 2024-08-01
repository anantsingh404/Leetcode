class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        int n=details.size();
        for(int i=n-1;i>=0;i--)
        {
            if(details[i].substr(11,2)>"60")
            {
                ++count;
            }
        }
        return count;
    }
};