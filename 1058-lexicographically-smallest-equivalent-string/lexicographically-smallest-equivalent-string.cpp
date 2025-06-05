class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string s) {
        int n=s1.size();
        vector<int> mp(26);
    for (int i = 0; i < 26; i++) {
        mp[i] = i;
    }
        for (int i = 0; i < n; i++) {
        int a = s1[i] - 'a';
        int b = s2[i] - 'a';
        int min_char = min(mp[a], mp[b]);
        int max_char = max(mp[a], mp[b]);

        for (int j = 0; j < 26; j++) {
            if (mp[j] == max_char) {
                mp[j] = min_char;
            }
        }
    }
        string ans;
         for (char ch : s) {
        ans += (char)(mp[ch - 'a'] + 'a');
    }
        return ans;
        
         
    }
};