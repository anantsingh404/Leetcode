class cmp {
public:
    bool operator()(const vector<int>& a, const vector<int>& b) {
        double ratioA = 1.0*(a[0]) / a[1];
        double ratioB = 1.0*(b[0]) / b[1];
        double improvementA = 1.0 * (a[0] + 1) / (a[1] + 1) - ratioA;
        double improvementB = 1.0 * (b[0] + 1) / (b[1] + 1) - ratioB;
        return improvementA < improvementB;
    }
};
class Solution {
public:

    double maxAverageRatio(vector<vector<int>>& classes, int ex) {
       int n = classes.size();
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    for (auto& c : classes) {
        pq.push(c);
    }

    while (ex > 0) {
        vector<int> topClass = pq.top();
        pq.pop();
        
        topClass[0]++;
        topClass[1]++;
        
        pq.push(topClass);
        
        ex--;
    }
   

    double ans = 0.0;
    while (!pq.empty()) {
        vector<int> topClass = pq.top();
        pq.pop();
        ans += 1.0*topClass[0]/topClass[1];
    }

    return ans / n;  
    }
};