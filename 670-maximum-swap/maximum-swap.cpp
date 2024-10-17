class Solution {
public:
    int maximumSwap(int num) {
      string x=to_string(num);
      int n=x.size();
      int i=n-1;
      int ans=num;
       while(i>0)
       {
        for(int j=0;j<i;j++)
        { if(x[i]>x[j]){
         swap(x[i],x[j]);
         int y=stoi(x);
         ans=max(ans,y);
         swap(x[i],x[j]);

        }
         
        }
        i--;
       }
       return ans;
    }
};