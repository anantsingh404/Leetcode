class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
       queue<pair<vector<vector<int>>,int>>q;
       q.push({board,0});
       int count=1000;
       set<vector<vector<int>>>st;
       st.insert(board);
       while(!q.empty() && count)
       {
         vector<vector<int>>p=q.front().first;
         int op=q.front().second;
         bool ans=true;
         int xx=-1;
         int yy=-1;
         for(int j=0;j<3;j++)
         {
            if(p[0][j]!=j+1)
            {
                ans=false;
            }
            if(p[0][j]==0)
            {
                xx=0;
                yy=j;
            }
         }
         for(int j=0;j<3;j++)
         {
            if(j==0 && p[1][j]!=4)
            {
                ans=false;
            }
            if(j==1 && p[1][j]!=5)
            {
                ans=false;
            }
            if(j==2 && p[1][j]!=0)
            {
                ans=false;
            }
             if(p[1][j]==0)
            {
                xx=1;
                yy=j;
            }
         }
         if(ans)
         {
            return op;
         }
         if(xx-1>=0)
         {
            swap(p[xx][yy],p[xx-1][yy]);
            if(st.find(p)==st.end())
            {
                st.insert(p);
                q.push({p,op+1});
            }
            swap(p[xx][yy],p[xx-1][yy]);
            
         }
          if(xx+1<2)
         {
            swap(p[xx][yy],p[xx+1][yy]);
            if(st.find(p)==st.end())
            {
                st.insert(p);
                q.push({p,op+1});
            }
            swap(p[xx][yy],p[xx+1][yy]);
            
         }
          if(yy-1>=0)
         {
            swap(p[xx][yy],p[xx][yy-1]);
            if(st.find(p)==st.end())
            {
                st.insert(p);
                q.push({p,op+1});
            }
            swap(p[xx][yy],p[xx][yy-1]);
            
         }
           if(yy+1<3)
         {
            swap(p[xx][yy],p[xx][yy+1]);
            if(st.find(p)==st.end())
            {
                st.insert(p);
                q.push({p,op+1});
            }
            swap(p[xx][yy],p[xx][yy+1]);
            
         }
         q.pop();
--count;
       }
       return -1;
    }
};