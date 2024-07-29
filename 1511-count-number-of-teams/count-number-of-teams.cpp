class Solution {
public:
    int numTeams(vector<int>& arr) {
       int n = arr.size();
    if (n < 3) return 0;

    vector<int> left_greater(n, 0);
    vector<int> left_less(n, 0);
    vector<int> right_greater(n, 0);
    vector<int> right_less(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                left_less[i]++;
            } else if (arr[j] > arr[i]) {
                left_greater[i]++;
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (arr[j] < arr[i]) {
                right_less[i]++;
            } else if (arr[j] > arr[i]) {
                right_greater[i]++;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        result += left_less[i] * right_greater[i];
        result += left_greater[i] * right_less[i];
    }

    return result;

    }
};