#include <vector>
#include <unordered_set>
#include <utility>  // for std::pair
#include <algorithm> // for std::max

using namespace std;

// Hash function for pairs to be used in unordered_set
struct hash_pair {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2; // Combine hash values
    }
};

class Solution {
public:
    int robotSim(vector<int>& com, vector<vector<int>>& ob) {
        int ans = 0;
        int dir = 0; // 0 = North, 1 = East, 2 = South, 3 = West
        int curx = 0;
        int cury = 0;
        
        // Use an unordered_set to store obstacles
        unordered_set<pair<int, int>, hash_pair> obstacles;
        for (const auto& o : ob) {
            obstacles.insert({o[0], o[1]});
        }

        for (int i = 0; i < com.size(); i++) {
            if (com[i] == -1) { // Turn right
                dir = (dir + 1) % 4;
            } else if (com[i] == -2) { // Turn left
                dir = (dir - 1 + 4) % 4;
            } else { // Move forward
                int steps = com[i];
                while (steps--) {
                    if (dir == 0) {
                        ++cury;
                    } else if (dir == 1) {
                        ++curx;
                    } else if (dir == 2) {
                        --cury;
                    } else if (dir == 3) {
                        --curx;
                    }
                    
                    if (obstacles.find({curx, cury}) != obstacles.end()) {
                        // If obstacle is encountered, stop moving
                        if (dir == 0) --cury;
                        else if (dir == 1) --curx;
                        else if (dir == 2) ++cury;
                        else if (dir == 3) ++curx;
                        break;
                    }
                }
                ans = max(ans, curx * curx + cury * cury);
            }
        }
        
        return ans;
    }
};
