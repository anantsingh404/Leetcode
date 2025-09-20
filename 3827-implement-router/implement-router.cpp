struct H {
    size_t operator()(const tuple<int, int, int>& t) const {
        auto [a, b, c] = t;
        return hash<int>{}(a)^(hash<int>{}(b) << 1)^(hash<int>{}(c) << 2);
    }
};

struct P {
    int a, b, c, d;
};

class Router {
public:
    int m;
    deque<P> q;
    unordered_set<tuple<int, int, int>, H> s;
    unordered_map<int, vector<pair<int, int>>> t;
    int g;
    int i;

    Router(int m) : m(m), g(0), i(0) {}

    bool addPacket(int a, int b, int c) {
        auto k = make_tuple(a, b, c);
        if (s.count(k))
        { 
            return false;
        }

        while (q.size() >= m) 
        {
            P p = q.front();
            q.pop_front();
            s.erase(make_tuple(p.a, p.b, p.c));
            i++;
        }

        int d = g++;
        q.push_back({a, b, c, d});
        s.insert(k);
        t[b].emplace_back(c, d);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty())
        {
            return {};
        }
        P p = q.front();
        q.pop_front();
        s.erase(make_tuple(p.a, p.b, p.c));
        i++;
        return {p.a, p.b, p.c};
    }

    int getCount(int a, int b, int c) {
        auto it = t.find(a);
        if (it == t.end())
        {
            return 0;
        }
        const auto& v = it->second;
        if (v.empty())
        {
            return 0;
        }

        auto l = lower_bound(v.begin(), v.end(), make_pair(b, 0),
            [](const pair<int, int>& x, const pair<int, int>& y)
           {
                return x.first < y.first;
            });

        auto u = upper_bound(v.begin(), v.end(), make_pair(c, INT_MAX),
            [](const pair<int, int>& x, const pair<int, int>& y)
            {
                return x.first < y.first;
            });

        int x = l - v.begin();
        int y = u - v.begin();
        if (x >= y) 
        {
            return 0;
        }
        int lo = x, hi = y-1, pos = y;
        while (lo <= hi)
            {
            int mid = (lo + hi) / 2;
            if (v[mid].second >= i)
            {
                pos = mid;
                hi = mid - 1;
            }
            else 
            {
                lo = mid + 1;
            }
        }

        return y - pos;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */