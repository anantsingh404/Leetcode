class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
     int n=nums.size();
     int flag=0;
   //  sort(nums.begin(),nums.end());
     int f=n;
     //cout<<f<<endl;
     while(f>=(1<<flag))
     {
        ++flag;
     } 
     --flag;
     while(flag>=0)
     {
        f=f|(1<<flag);
        --flag;
     }
    // cout<<f<<endl;
     if(n>=3)
     {
        return f+1;
     }
     return  n;


    }
};