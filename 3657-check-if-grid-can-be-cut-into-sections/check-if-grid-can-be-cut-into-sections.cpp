class Solution {
public:
 vector<pair<int, int>> v;
bool canDivide(vector<vector<int>>& rects, bool vert) {
   v.resize(rects.size());
    int i = 0;
      
    vector<int> L, R;
    while (i < rects.size())
        {
        if (vert)
            v[i] = {rects[i][0], rects[i][2]};
        else
            v[i] = {rects[i][1], rects[i][3]};
        i++;
    }

    
    int sz = v.size();
   
   vector<bool> vl(sz, false);
    vector<bool>vr(sz, false);
     vector<int> pmax(sz);
    vector< int>smin(sz);
    vector<int>st(sz);
    vector<int>en(sz);
    sort(v.begin(), v.end());
    i = 0;
    while (i < sz)
    {
        st[i] = v[i].first;
        en[i] = v[i].second;
        i++;
    }

    pmax[0] = en[0];
    i = 1;
    while (i < sz)
    
    {
        pmax[i] = max(pmax[i - 1], en[i]);
        i++;
    }

    smin[sz - 1] = st[sz - 1];
    i = sz - 2;
    while (i >= 0)
    {
        smin[i] = min(smin[i + 1], st[i]);
        i--;
    }

  
    i = 0;
    while (i + 1 < sz) {
        if (pmax[i] <= st[i + 1]) vl[i] = true;
        i++;
    }

    i = 1;
    while (i < sz) {
        if (smin[i] >= en[i - 1]) vr[i] = true;
        i++;
    }

    
    i = 0;
    while (i + 1 < sz) {
        if (vl[i]) L.push_back(i);
        i++;
    }

    i = 1;
    while (i < sz) {
        if (vr[i]) R.push_back(i);
        i++;
    }

    int idx = 0;
    for (auto l : L)
        {
        while (idx < R.size() && R[idx] <= l + 1) idx++;
        while (idx < R.size()) 
        {
            int r = R[idx];
            if (r <= l + 1) 
            {
                idx++;
                continue;
            }
            if (r - 1 >= l + 1) 
            {
                int mxE = pmax[r - 1], mnS = smin[l + 1];
                if (mxE <= (r < sz ? st[r] : INT_MAX) &&
                    mnS >= (l >= 0 ? en[l] : INT_MIN)) {
                    return true;
                }
            }
            idx++;
        }
    }
    return false;
}
    bool checkValidCuts(int n, vector<vector<int>>& rects) {
       return canDivide(rects, true) || canDivide(rects, false); 
    }
};