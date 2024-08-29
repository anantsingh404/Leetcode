class DisjointSet{
public:
    vector <int> parent,size;
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionSize(int u,int v){
        int up = findUPar(u);
        int vp = findUPar(v);
        if(up == vp) return;
        if(size[up] < size[vp]){
            parent[up] = vp;
            size[vp] += size[up];
        }
        else{
            parent[vp] = up;
            size[up] += size[vp];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
            int mxr = 1,mxc = 1,ans = 0;
        for(auto i:stones){
            mxr = max(mxr,i[0]+1);
            mxc = max(mxc,i[1]+1);
        }
        DisjointSet ds(mxr+mxc);
        for(auto i:stones)
            ds.unionSize(i[0],mxr+i[1]);
        for(int i = 0;i < mxr+mxc;i++){
            if(ds.parent[i] == i && ds.size[i] > 1)
                ans++;
        }
        return stones.size()-ans;
    }
};