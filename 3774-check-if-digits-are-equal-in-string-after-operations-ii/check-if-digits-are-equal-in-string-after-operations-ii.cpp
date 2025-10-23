class Solution {
public:
    // For CRT
    const int MOD = 10;  
    const int MAXN = 1e6; // you can adjust if needed

    vector<int> fact2, fact5;
    vector<int> invFact2, invFact5;

    // Precompute factorials modulo p
    void precomputeFactorials(int p, vector<int> &fact, vector<int> &invFact) {
        fact[0] = 1;
        for (int i = 1; i < p; i++) {
            fact[i] = (fact[i - 1] * i) % p;
        }
        invFact[p - 1] = modPow(fact[p - 1], p - 2, p);
        for (int i = p - 2; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % p;
        }
    }

    // Fast exponentiation
    int modPow(int a, int b, int m) {
        int res = 1;
        a = a % m;
        while (b > 0) {
            if (b % 2) res = (res * a) % m;
            a = (a * a) % m;
            b /= 2;
        }
        return res;
    }

    // Compute nCr mod p using factorial precomputation
    int nCrModP(int n, int r, int p, vector<int> &fact, vector<int> &invFact) {
        if (r < 0 || r > n) return 0;
        int res = (1LL * fact[n % p] * invFact[r % p]) % p;
        res = (1LL * res * invFact[(n - r) % p]) % p;
        return res;
    }

    // Compute nCr mod 2 using Lucas Theorem
    int nCrMod2(int n, int r) {
        int res = 1;
        while (n > 0 || r > 0) {
            int ni = n % 2;
            int ri = r % 2;
            if (ri > ni) return 0;
            n /= 2;
            r /= 2;
        }
        return 1;
    }

    // Compute nCr mod 5 using Lucas Theorem
    int nCrMod5(int n, int r) {
        int res = 1;
        while (n > 0 || r > 0) {
            int ni = n % 5;
            int ri = r % 5;
            if (ri > ni) return 0;
            res = (res * nCrModP(ni, ri, 5, fact5, invFact5)) % 5;
            n /= 5;
            r /= 5;
        }
        return res;
    }

    // Combine results using CRT
    int nCrMod10(int n, int r) {
        int a2 = nCrMod2(n, r);
        int a5 = nCrMod5(n, r);
        int x = (a5 * 2 * 3 + a2 * 5 * 1) % 10; // 2^-1 mod5 =3, 5^-1 mod2=1
        return x;
    }

    bool temp = true;
    bool hasSameDigits(string s) {
        if (temp) {
            fact5.assign(5, 1);
            invFact5.assign(5, 1);
            precomputeFactorials(5, fact5, invFact5);
            temp = false;
        }

        int n = s.size();
        int x = 0, y = 0;
        for (int i = 0; i < n - 1; i++) {
            x = (x + 1LL * (s[i] - '0') * nCrMod10(n - 2, i)) % 10;
        }
        int p=0;
        for (int i = n - 1; i > 0; i--) {
            y = (y + 1LL * (s[i] - '0') * nCrMod10(n - 2, p++)) % 10;
        }
        cout<<x<<" "<<y<<endl;
        return x == y;
    }
};