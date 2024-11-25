class Solution {
public:

    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {
      int n=nums.size();
sort(q.begin(),q.end());
priority_queue<int>maxi;
priority_queue<int,vector<int>,greater<int>>mini;

int count=0;
int j=0;
for(int i=0;i<nums.size();i++)
       {
      while(j<q.size() && q[j][0]==i)
      {
        maxi.push(q[j][1]);
        j++;
      }
      nums[i]-=mini.size();
      while(nums[i]>0 && !maxi.empty() && maxi.top()>=i)
      {
        mini.push(maxi.top());
        --nums[i];
    maxi.pop();
        ++count;
      }
      if(nums[i]>0)
      {
        return -1;
      }
      while(!mini.empty() && mini.top()==i)
      {
        mini.pop();
      }
       }
       return q.size()-count;
        
    }
};