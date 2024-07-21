class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long count=0;
        long long incr=0;
        long long decr=0;

      for(int i=0;i<nums.size();i++)
      {
        long long int diff=target[i]-nums[i];
        if(diff>0)
        {
            if(incr<diff){
            count+=diff-incr;
            
            }
            incr=diff;
             decr=0;
        }
        else if(diff<0)
        {   if(-diff>decr){
            count+=(-diff)-decr;
            
        }
        decr=-diff;
            incr=0;
        }
        else
        {
            incr=0;
            decr=0;
        }
      }
      return count;  
    }
};