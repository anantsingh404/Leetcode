class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
      int ca=a;
      int cb=b;
      int cc=c;
     int count=a+b+c;
     string ans;
     int i=0;
     int cca=0;
     int ccb=0;
     int ccc=0;
    while(i<count)
    {
       if((cca!=2 && ca>=cb && ca>=cc) || (ca>0 && (ccb==2 || ccc==2)))
       {
        ans+='a';
        cca++;
        ccb=0;
        ccc=0;
        --ca;
       }
       else if((ccb!=2 && cb>=ca && cb>=cc) || (cb>0 && (cca==2 || ccc==2)))
       {
        ans+='b';
        ccb++;
        cca=0;
        ccc=0;
        --cb;
       }
       else if((ccc!=2 && cc>=ca && cc>=cb) || (cc>0 && (cca==2 || ccb==2)))
       {
        ans+='c';
        ccc++;
        cca=0;
        ccb=0;
        --cc;
       }
       i++;
    }
    return ans;
}
};