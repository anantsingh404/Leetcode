class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
      int total=n*2;
      sort(rs.begin(),rs.end());
      int i=0;
      while(i<rs.size())
      {
        int first=1;
        int second=1;
        int third=1;
        int j=i;
        while(j<rs.size() && rs[j][0]==rs[i][0])
        {
            int x=rs[j][1];
            if(x==2 || x==3 ||x==4 || x==5)
            {
                first=0;
            }
             if(x==4 || x==5 ||x==6 || x==7)
            {
                second=0;
            }
             if(x==6 || x==7 || x==8 || x==9)
            {
                third=0;
            }
            j++;
        }
       if (first && third) {
                // Both blocks are free, accommodates 2 families
                total -= 0; 
            } else if (first || second || third) {
                // At least one block is free, accommodates 1 family
                total -= 1; 
            } else {
                // No blocks are free, accommodates 0 families
                total -= 2; 
            }
        i=j;
      } 
      return total; 
    }
};