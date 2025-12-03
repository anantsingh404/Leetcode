int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class ParallelogramsCounter {
public:
    void add(int pos) {
        ++counts_[pos];
        ++total_;
    }

    int total() const {
        int result = 0;
        for (auto [_, count] : counts_) {
            result += (total_ - count) * count;
        }
        return result / 2;
    }

private:
    int total_ = 0;
    std::unordered_map<int, int> counts_;
};

class Solution {
    int countTrapezoidsImpl(const std::vector<std::vector<int>>& points,
                            bool normalize) {
        std::unordered_map<int, ParallelogramsCounter> counters;

        for (int i = 1; i < (int)points.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (normalize) {
                    int g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;
                }

                
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }
                int key = 10000 * dx + dy;
                int height = dy * points[j][0] - dx * points[j][1];

                counters[key].add(height);
            }
        }

        int result = 0;
        for (const auto& [_, counter] : counters) {
            result += counter.total();
        }

        
        if (!normalize) {
            result >>= 1;
        }
        return result;
    }

public:
    int countTrapezoids(std::vector<std::vector<int>>& points) {
        int trapezoidsWithMultiplicity = countTrapezoidsImpl(points, true);
        int parallelograms = countTrapezoidsImpl(points, false);
        return trapezoidsWithMultiplicity - parallelograms;
    }
};