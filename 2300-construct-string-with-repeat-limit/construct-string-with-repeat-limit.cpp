class Solution {
public:
    string repeatLimitedString(string s, int rl) {
      unordered_map<char, int> freq;
    priority_queue<pair<char, int>> pq;

    // Count frequencies of each character
    for (char ch : s) {
        freq[ch]++;
    }

    // Push characters into the max heap (priority_queue)
    for (auto& itr : freq) {
        pq.push({itr.first, itr.second});
    }

    string ans = "";
    while (!pq.empty()) {
        auto [ch1, cnt1] = pq.top();
        pq.pop();

        int repeat = min(cnt1, rl); // Use the character up to `repeatLimit` times
        ans.append(repeat, ch1);   // Append the character `repeat` times
        cnt1 -= repeat;

        if (cnt1 > 0) { // If there are more characters left to process
            if (pq.empty()) break; // No more characters to "break" the sequence
            
            auto [ch2, cnt2] = pq.top();
            pq.pop();

            ans.push_back(ch2); // Use one character to break the sequence
            cnt2--;

            // Push the remaining counts back into the heap if still available
            if (cnt2 > 0) pq.push({ch2, cnt2});
            if (cnt1 > 0) pq.push({ch1, cnt1});
        }
    }
    return ans;  
    }
};