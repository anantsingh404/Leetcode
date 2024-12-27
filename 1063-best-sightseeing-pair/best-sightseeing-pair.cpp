class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
      int n=values.size();
      priority_queue<int>pq;
      pq.push(values[n-1]-(n-1));
      int i=n-2;
      int ans=0;
      while(i>=0)
      {
        int x=pq.top();
         int y=values[i]+i;
         ans=max(ans,y+pq.top());
         pq.push(values[i]-i);
         i--;
      }
      return ans;

    }
};