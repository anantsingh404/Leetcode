class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
     int mini=-1;
     int minival=INT_MAX;
     int maxival=INT_MIN;
     int maxi=-1;
     int n=nums.size();
     for(int i=0;i<nums.size();i++)
     {
        if(maxival<nums[i]){
            maxival=nums[i];
            maxi=i;
        }
        if(minival>nums[i])
        {
            minival=nums[i];
            mini=i;
        }
     }
     int dis=abs(mini-maxi)-1;
     int leftmost=min(mini,maxi);
     int rightmost=max(mini,maxi);
     int a=min(n-leftmost,rightmost+1);
     
     return min(a,n-dis);   
    }
};