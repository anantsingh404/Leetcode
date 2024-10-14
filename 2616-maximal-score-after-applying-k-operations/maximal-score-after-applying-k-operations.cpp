class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
      long long ans=0;
      priority_queue<int>pq(nums.begin(),nums.end());
      while(k--)
      {
        int x=pq.top();
        pq.pop();
        ans+=x;
        int p=x/3;
        if(x%3)
        {++p;
        }
        pq.push(p);
      }
      return ans;  
    }
};