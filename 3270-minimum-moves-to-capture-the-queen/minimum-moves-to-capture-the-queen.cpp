class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
     if(a==e)
     {
        if(c==e){
                if(d>=max(b,f) || d<=min(b,f)) return 1;
            } 
            else return 1;
     } 
     if(b==f) {
             if(d==f){
                if(c>=max(a,e) || c<=min(a,e)) return 1;
            } 
            else return 1;
        }  
        if(c+d==e+f){
            if(a+b==c+d){
                if(a>=max(c,e) || a<=min(c,e)) return 1;
            }
            else return 1;
        }
        if(c-d==e-f){
            if(a-b==c-d){
                if(a>=max(c,e) || a<=min(c,e)) return 1;
            }
            else return 1;
        }
        return 2;
    }
};