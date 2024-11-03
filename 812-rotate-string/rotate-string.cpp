class Solution {
public:
    bool rotateString(string s, string goal) {
       int count=0;
       int n=s.size();
       while(count<n)
       {
        if(s==goal)
        {
            return true;
        }
        char x=s.back();
        s.pop_back();
        s=x+s;
        ++count;
       }
       return false;

    }
};