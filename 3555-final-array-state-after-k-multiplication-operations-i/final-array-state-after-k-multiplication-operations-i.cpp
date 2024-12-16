class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       for(int i=0;i<nums.size();i++)
       {
pq.push({nums[i],i});
       }
       while(k--)
       {
        pair<int,int>x=pq.top();
        pq.pop();
        x.first=x.first*mul;
        pq.push(x);
       }
       while(!pq.empty())
       {
        pair<int,int>p=pq.top();
        nums[p.second]=p.first;
        pq.pop();
       }
       return nums;
    }
};