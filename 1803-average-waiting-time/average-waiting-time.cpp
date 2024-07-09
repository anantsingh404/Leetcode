class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
      double ans=0.0;
      int prev=cust[0][0];
      double wt=0;
      int n=cust.size();
      for(int i=0;i<cust.size();i++)
      { // ++prev;
        if(cust[i][0]<=prev){
        prev+=cust[i][1];

        wt+=prev-cust[i][0];
       // cout<<prev<<endl;
        cout<<wt<<endl;
        }else
        {
            prev=cust[i][0];
            prev+=cust[i][1];

        wt+=prev-cust[i][0];
        }
      }
      return wt/n;

    }
};