class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
          long long anss = 0;
    int n = word1.size();
    int m = word2.size();
    
    
    unordered_map<int, int> mp;
    for (char c : word2) {
        mp[c-'a']++;
    }

    // Frequency count of characters in current substring of word1
    vector<int> freq(26, 0);
    int j = 0;  // Start index of the current substring

    for (int i = 0; i < n; i++) {
        freq[word1[i] - 'a']++; 

        while (j <= i && freq[word1[j] - 'a'] > mp[word1[j] - 'a']) {
            freq[word1[j] - 'a']--;  
            j++;
        }
        bool ans=true;
        for(auto itr:mp)
        {
            if(mp[itr.first]>freq[itr.first])
            {
                ans=false;
            }
        }
        if(ans){
        anss += (j+1);
        }
    }
    
    return anss;
    }
};