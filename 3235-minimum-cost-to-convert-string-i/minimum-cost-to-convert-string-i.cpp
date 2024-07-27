class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int e[26][26];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                e[i][j] = 1e9 + 10;
            }
            e[i][i] = 0;
        }
        for (int i = 0; i < cost.size(); i++) {
            e[original[i] - 'a'][changed[i] - 'a'] = min(e[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
                for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                    e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
                }
            }
        } 
        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (e[source[i] - 'a'][target[i] - 'a'] > 1e9) {
                return -1;
            }
            ans += e[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};