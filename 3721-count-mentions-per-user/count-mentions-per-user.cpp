class Solution {
public:
struct a {
    int b;
    int c;
};

struct d {
    bool operator()(const a& e, const a& f) const {
        return e.b > f.b;
    }
};
    vector<int> countMentions(int h, vector<vector<string>>& i) {
         vector<int> l(h, 0);
        vector<bool> m(h, true);
          priority_queue<a, vector<a>, d> n;
         sort(i.begin(), i.end(), [&](const vector<string>& j, const      vector<string>& k) -> bool {
            return stoi(j[1]) < stoi(k[1]);
        });

       

      
        
        int o = i.size();
        int p = 0;
        
        while (p < o) 
        {
            int q = stoi(i[p][1]);

            while (!n.empty() && n.top().b <= q)
                {
                int r = n.top().c;
                if (r >= 0 && r < h) {
                    m[r] = true;
                }
                n.pop();
            }

            int s = p;
            while (s < o && stoi(i[s][1]) == q) 
            {
                s++;
            }

            int t = p;
            while (t < s) {
                if (i[t][0] == "OFFLINE")
                {
                    int u = stoi(i[t][2]);
                    if (u >= 0 && u < h && m[u]) 
                    {
                        m[u] = false;
                        a v;
                        v.b = q + 60;
                        v.c = u;
                        n.push(v);
                    }
                }
                t++;
            }

            int w = p;
            while (w < s) {
                if (i[w][0] == "MESSAGE")
                {
                    string x = i[w][2];
                    
                    if (x == "ALL") {
                        int y = 0;
                        while (y < h) {
                            l[y]++;
                            y++;
                        }
                    }
                    else if (x == "HERE")
                    {
                        int y = 0;
                        while (y < h)
                            {
                            if (m[y]) 
                            {
                                l[y]++;
                            }
                            y++;
                        }
                    }
                    else {
                        stringstream z(x);
                        string aa;
                        while (z >> aa) 
                        {
                            if (aa.size() >= 3 && aa.substr(0, 2) == "id")
                            {
                                string bb = aa.substr(2);
                                bool cc = true;
                                int dd = 0;
                                while (dd < bb.size()) 
                                {
                                    if (!isdigit(bb[dd])) 
                                    {
                                        cc = false;
                                        break;
                                    }
                                    dd++;
                                }
                                if (cc) 
                                {
                                    int ee = stoi(bb);
                                    if (ee >= 0 && ee < h) 
                                    {
                                        l[ee]++;
                                    }
                                }
                            }
                        }
                    }
                }
                w++;
            }

            p = s;
        }
        
        return l;
    }
};