class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
     int x=-1,y=-1;
     int n=nums.size();
     for(int i=0;i<nums.size();i++)
     {
        int p=nums[i]%n;
        nums[p]+=n;

     }
     for(int i=0;i<n;i++)
     {
        if(nums[i]/n>1 && x==-1){
            x=i;
        }
        if(nums[i]/n>1 && x!=-1){
            y=i;
        }
     }
     return {x,y};   
    }
};