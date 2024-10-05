class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        if (n > m) return false;
        
        vector<int> mp(26, 0);
        vector<int> windowFreq(26, 0);
        
        for (int i = 0; i < n; i++) {
            mp[s1[i] - 'a']++;
            windowFreq[s2[i] - 'a']++;
        }
        
        if (mp == windowFreq) return true;
        
        for (int i = n; i < m; i++) {
            windowFreq[s2[i] - 'a']++;
            windowFreq[s2[i - n] - 'a']--;
            
            if (mp == windowFreq) return true;
        }
        
        return false;
    }
};
