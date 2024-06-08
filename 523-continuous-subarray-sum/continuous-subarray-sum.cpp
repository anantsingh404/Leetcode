class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int sm = 0,n = nums.size();
        for(int i=0;i<n;i++){
            sm += nums[i];
            sm %= k;

            if(sm==0 && i>0)
                return true;

            if(mp.find(sm)==mp.end())
                mp[sm] = i;
            else{
                if((i-mp[sm])>1)
                    return true;
            }
        }
        return false;
    }
};