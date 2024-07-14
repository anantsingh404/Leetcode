class Solution {
public:
    string getSmallestString(string s) {
       for(int i=0;i<s.size()-1;i++)
       {
        if(s[i]%2 && s[i+1]%2 && s[i]>s[i+1])
        {
            swap(s[i],s[i+1]);
            return s;
        }
        else if(s[i]%2==0 && s[i+1]%2==0 && s[i]>s[i+1])
        {
            swap(s[i],s[i+1]);
            return s;
        }
       } 
       return s;
    }
};