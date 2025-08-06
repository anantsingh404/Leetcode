class SegmentTree {
private:
    vector<int> a;
    int b;

    void c(const vector<int>& d, int e, int f, int g) 
{
        if (f == g) 
        {
            a[e] = d[f];
        }
        else 
        {
            int h = (f + g) / 2;
            c(d, 2 * e + 1, f, h);
            c(d, 2 * e + 2, h + 1, g);
            a[e] = max(a[2 * e + 1], a[2 * e + 2]);
        }
    }

    int i(int e, int f, int g, int h, int j, int k) {
        if (f > j || g < h || a[e] < k)
        {
            return -1;
        }
        if (f == g)
        {
            return f;
        }
        int l = (f + g) / 2;
        int m = i(2 * e + 1, f, l, h, j, k);
        if (m != -1)
        {
            return m;
        }
        return i(2 * e + 2, l + 1, g, h, j, k);
    }

    void n(int e, int f, int g, int h, int k) {
        if (f == g) 
        {
            a[e] = k;
        } 
        else
        {
            int l = (f + g) / 2;
            if (h <= l) 
            {
                n(2 * e + 1, f, l, h, k);
            } 
            else 
            {
                n(2 * e + 2, l + 1, g, h, k);
            }
            a[e] = max(a[2 * e + 1], a[2 * e + 2]);
        }
    }

public:
    SegmentTree(const vector<int>& d)

{
        b = d.size();
        a.resize(4 * b);
        c(d, 0, 0, b - 1);
    }

    int o(int k)
{
        return i(0, 0, b - 1, 0, b - 1, k);
    }

    void p(int h)
{
        n(0, 0, b - 1, h, -1);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& q, vector<int>& r) {
        SegmentTree s(r);
        int t = 0;

        for (int u : q) 
        {
            int v = s.o(u);
            if (v == -1)
            {
                t++;
            } 
            else 
            {
                s.p(v);
            }
        }

        return t;
    }
};