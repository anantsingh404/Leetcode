class Solution {
public:
    string compressedString(string word) {
        int i=0;
        string ans="";
        while(i<word.size())
        {
            int j=i;
            int count=0;
            string flag="";
            while(j<word.size() && j<i+9 && word[j]==word[i])
            {
                ++count;
                ++j;
            }
            
            string x=to_string(count);
            ans+=x;
            ans.push_back(word[i]);
            i=j;
        }
        return ans; 
    }
};