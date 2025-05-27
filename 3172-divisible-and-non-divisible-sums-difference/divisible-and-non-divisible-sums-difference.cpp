class Solution {
public:
    int differenceOfSums(int n, int m) {
      int sum=((n)*(n+1))/2;  
      
      int y=n/m;
      int z=(y*m*(y+1))/2;
      sum-=z;
      //cout<<sum<<" "<<z<<endl;



      return sum-z;
    }
};