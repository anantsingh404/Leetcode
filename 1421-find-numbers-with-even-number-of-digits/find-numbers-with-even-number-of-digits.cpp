class Solution {
public:
    int findNumbers(vector<int>& nums) {
       int count=0;
       for(int i=0;i<nums.size();i++)
       {
        string x=to_string(nums[i]);
        count+=(x.size()+1)%2;
       }
       return count; 
    }
};