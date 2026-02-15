class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()) swap(a,b);

        int n = a.size();
        int m = b.size();

        // add b into a
        for(int i = 0;i<m;i++){
            a[n - 1 - i] += b[m - 1 - i] - '0';
        }

        // propagate carry        
        for(int i = n-1; i > 0; i--){
            if(a[i] >= '2'){a[i] = a[i] - 2; a[i-1] += 1;}
        }
 
        // handle leading carry     
        if(a[0] >= '2'){
            a[0] = a[0] - 2;
            a = "1" + a;
        }
        
        return a;
    }
};