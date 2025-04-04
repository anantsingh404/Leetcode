class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
      priority_queue<long long,vector<long long>,greater<long long>>pq(nums.begin(),nums.end());
      int count=0;
      while(pq.size()>1 && pq.top()<k)
      {
        long long x=pq.top();
        pq.pop();
        long long y=pq.top();
        pq.pop();
        ++count;
        pq.push(1ll*min(x,y)*2+max(x,y));
      }
      return count;

    }
};