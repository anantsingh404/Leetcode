class Solution {
public:
    long long countOfSubstrings(string word, long long k) {
        long long n = word.size();
        long long j = 0, ans = 0;
        long long consonantCount = 0;
        long long vowelMap[26] = {0};    // Array for vowel counts
        long long tempVowelMap[26] = {0}; // Array for temporary vowel counts
        long long flag = 0;
        
        for (long long i = 0; i < n; i++) {
            // Check if it's a consonant
            if (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u') {
                consonantCount++;
            } else {
                vowelMap[word[i] - 'a']++;  // Increment vowel count in vowelMap
            }

            // Adjust the sliding window if consonant count exceeds 'k'
            while (j <= i && consonantCount > k) {
                if (word[j] != 'a' && word[j] != 'e' && word[j] != 'i' && word[j] != 'o' && word[j] != 'u') {
                    consonantCount--;
                } else {
                    if (j >= flag) {
                        tempVowelMap[word[j] - 'a']++;  // Update tempVowelMap when we remove vowels
                    }
                }
                j++;
            }

            flag = max(flag, j);
           
            // Adjust flag polong longer to ensure we are managing vowel conditions properly
            while (flag <= i && (word[flag] == 'a' || word[flag] == 'e' || word[flag] == 'i' || word[flag] == 'o' || word[flag] == 'u')) {
                if (vowelMap[word[flag] - 'a'] - tempVowelMap[word[flag] - 'a'] > 1) {
                    tempVowelMap[word[flag] - 'a']++;
                    flag++;
                } else {
                    break;
                }
            }

            // Check condition: consonant count should be exactly 'k'
            bool validSubstring = true;
            for (long long x = 0; x < 26; x++) {
                char ch = 'a' + x;
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    if (vowelMap[x] == tempVowelMap[x]) {
                        validSubstring = false;
                        break;
                    }
                }
            }

            // Debugging output
           // cout << vowelMap['o' - 'a'] << " " << tempVowelMap['o' - 'a'] << " " << flag << " " << validSubstring << " " << consonantCount << endl;
            
            // If conditions are met, count this as a valid substring
            if (flag >= j && validSubstring && consonantCount == k) {
                ans += flag - j + 1;
            }
            
            // Debugging output
           // cout << ans << endl;
        }
        
        return ans;
    }
};
