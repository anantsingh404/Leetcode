class Spreadsheet {
public:
vector<vector<int>>dp;
    Spreadsheet(int rows) {
        dp.resize(rows+1,vector<int>(26));
        dp.assign(rows+1,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
       int col=cell[0]-'A';
       int row=stoi(cell.substr(1,cell.size()-1));
       dp[row][col]=value; 
    }
    
    void resetCell(string cell) {
        int col=cell[0]-'A';
       int row=stoi(cell.substr(1,cell.size()-1));
       dp[row][col]=0;
    }
    
    int getValue(string f) 
    {  int xx=0;
    int yy=0;
        int e = f.find('+');
       if(f[1]>='A' && f[1]<='Z')
       {
        
         string ff = f.substr(1,e-1);
         int c1=ff[0]-'A';
         int r1=stoi(ff.substr(1,ff.size()-1));
          xx=dp[r1][c1];
        }
        else
        {
           string ff = f.substr(1,e-1);
         
          xx=stoi(ff); 
        }
         if(f[e+1]>='A' && f[e+1]<='Z')
       {
        
         string ff = f.substr(e+1);
         int c1=ff[0]-'A';
         int r1=stoi(ff.substr(1,ff.size()-1));
          yy=dp[r1][c1];
        }
        else
        {
           string ff = f.substr(e+1);
         
          yy=stoi(ff); 
        }

        return xx+yy;

    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */