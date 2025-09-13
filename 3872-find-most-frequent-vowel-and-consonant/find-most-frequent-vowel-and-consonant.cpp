class Solution {
public:
    int maxFreqSum(string s) {
      set<int>ss;
      ss.insert('a'-'a');
      ss.insert('e'-'a');
      ss.insert('i'-'a');ss.insert('o'-'a');
      ss.insert('u'-'a');unordered_map<int,int>v,c;
      int max1=0,max2=0;
      for(int i=0;i<s.size();i++){
        if(ss.find(s[i]-'a')!=ss.end()){
            ++v[s[i]-'a'];
            max1=max(max1,v[s[i]-'a']);
        }

        else
        {
            ++c[s[i]-'a'];
             max2=max(max2,c[s[i]-'a']);
        }
      }
      return max1+max2;

    }
};