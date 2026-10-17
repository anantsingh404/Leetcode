class Solution {
public:
   int f(int x)
    {
    int y = 0;
    while (x > 0) 
    {
        y += x % 10;
        x /= 10;
    }
    return y;
}

int minSwaps(vector<int>& a) 
    {
    int b=a.size();
    vector<pair<int,int>>c(b);
    for (int i =0;i<b;i++) 
    {
        c[i] = {f(a[i]), a[i]};
    }

    vector<pair<pair<int, int>,int>>d(b);
    for (int i = 0; i < b; i++) 
    {
        d[i]={c[i],i};
    }

    sort(d.begin(),d.end());
    vector<bool>e(b,false);
    int ans=0;
    for (int i=0;i<b;i++) 
    {
        if (e[i] || d[i].second==i)
        {
            continue;
        }

        int j=i,cnt=0;
        while(!e[j]) 
        {
            e[j]=true;
            j=d[j].second;
            cnt++;
        }
        if(cnt>1)
        {
            ans+=cnt-1;
        }
    }
    return ans;
}
};