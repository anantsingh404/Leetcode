class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        int n=nums.size();
        int l=1, r=*max_element(nums.begin(), nums.end()), m;
        while(l<r){
            m=l+(r-l)/2;
            long long cnt=0;
            for(int j=0; j<n && cnt<=k; j++)
                cnt+=(nums[j]-1)/m;
            if(cnt<=k) r=m;
            else l=m+1;
        }
        return r; 
    }
};