class Solution {
public:
int LIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp;
        for (const auto &num : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end()) dp.push_back(num);
            else *it = num;
        }
        return dp.size();
    }
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
    return a[0] < b[0];
}
    int maxPathLength(vector<vector<int>>& cor, int k) {
      int x=cor[k][0];
       int y=cor[k][1];
        int n=cor.size();
        sort(cor.begin(),cor.end(),cmp);
        int idx=-1;
        for(int i=0;i<cor.size();i++)
        {
            if(cor[i][0]==x && cor[i][1]==y)
            {
               idx=i;
                break;
            }
        }
        int ans1=0;
        int ans2=0;
       /* cout<<idx<<endl;
        vector<pair<int,int>>vp1;
        for(int i=0;i<idx;i++)
        {   if(cor[i][0]<x && cor[i][1]<y){
            
             while(!vp1.empty() && (vp1.back().first>=cor[i][0] || vp1.back().second>=cor[i][1]))
             {
                vp1.pop_back();
             }
             vp1.push_back({cor[i][0],cor[i][1]});
           }
        int x=vp1.size();
        
        ans1=max(ans1,x);
        }
         vector<pair<int,int>>vp2;
         for(int i=idx+1;i<cor.size();i++)
        {   if(cor[i][0]>x && cor[i][1]>y){
            while(!vp2.empty() && (vp2.back().first>=cor[i][0] || vp2.back().second>=cor[i][1]))
             {
                vp2.pop_back();
             }
             vp2.push_back({cor[i][0],cor[i][1]});
        }
         int x=vp2.size();
        
        ans2=max(ans2,x);
        }
        return ans1+ans2+1;
     
           */
           vector<int> less;
        vector<int> more;
        for (auto &c : cor) {
            int cx = c[0], cy = c[1];
            if (cx > x && cy > y) more.push_back(cy);
            if (cx < x && cy < y) less.push_back(cy);
        }
        ans1 = LIS(less);
        ans2 = LIS(more); 
        return ans1 + ans2 + 1; 
        
             
        
        
        
    }
};