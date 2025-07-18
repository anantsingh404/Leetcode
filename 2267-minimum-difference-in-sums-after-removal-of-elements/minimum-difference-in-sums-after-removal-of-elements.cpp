class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int m=n/3;
      vector<long long>right(n,0);  
      vector<long long>left(n,0);
      priority_queue<long long,vector<long long>,greater<long long>>pq;
       priority_queue<long long>pq1;
      long long sum=0;
      for(int i=n-1;i>=0;i--)
      { sum+=nums[i];
        pq.push(nums[i]);
        if(pq.size()>m)
        {
            sum-=pq.top();
            pq.pop();
        }
        right[i]=sum;
      }
      sum=0;
      for(int i=0;i<n;i++)
      {
       sum+=nums[i];
       pq1.push(nums[i]);
       if(pq1.size()>m)
       {
        sum-=pq1.top();
        pq1.pop();

       }
       left[i]=sum;
      }
      long long ans=LLONG_MAX;
      for(int i=m-1;i<n-m;i++)
      {
        ans=min(ans,left[i]-right[i+1]);
      }
      return ans;

    }
};