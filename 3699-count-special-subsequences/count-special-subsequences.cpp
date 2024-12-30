class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
      map<double,int> mpp;
        int n;
        long long ans=0;
        n=nums.size();
        for(int i=2;i<n;i++){
            for(int j=0;j<=i-4;j++)
                mpp[(double)nums[i-2]/nums[j]]++;
            for(int j=i+2;j<n;j++){
                double wanted=(double)nums[i]/nums[j];
                ans+=mpp[wanted];
            }
        }
        return ans;  
    }
};