class Solution {
public:
     vector<long long> f;
    long long get(vector<int>& a,int n){
        long long t=f[n],z=0;
        for(int i=0;i<10;i++)t/=f[a[i]];
        if(a[0]>0){
            vector<int> b=a;
            b[0]--;
            z=f[n-1];
            for(int i=0;i<10;i++)z/=f[b[i]];
        }
        return t-z;
    }
    string sig(vector<int>& a){
        string s="";
        for(int i=0;i<10;i++)s+=to_string(a[i])+"#";
        return s;
    }
    string make(int x,int n){
        string t=to_string(x),y=t;
        if(n%2==0){
            reverse(y.begin(),y.end());
            t+=y;
        }else{
            y=t.substr(0,t.size()-1);
            reverse(y.begin(),y.end());
            t+=y;
        }
        return t;
    }
public:
    long long countGoodIntegers(int n,int k){
        f=vector<long long>(n+1);
        f[0]=1;
        for(int i=1;i<=n;i++)f[i]=f[i-1]*i;
        unordered_set<string> s;
        long long ans=0;
        int h=(n+1)/2;
        int st=1;
        if(h>1)st=pow(10,h-1);
        int en=pow(10,h);
        for(int x=st;x<en;x++){
            string t=make(x,n);
            long long v=stoll(t);
            if(v%k!=0)continue;
            vector<int> a(10,0);
            for(char c:t)a[c-'0']++;
            string g=sig(a);
            if(s.count(g))continue;
            s.insert(g);
            ans+=get(a,n);
        }
        return ans;
    }
};