class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char target) {
       int idx=upper_bound(l.begin(),l.end(),target)-l.begin(); 
       if(idx==l.size())
       {
        return l[0];
       }
       return l[idx];
    }
};