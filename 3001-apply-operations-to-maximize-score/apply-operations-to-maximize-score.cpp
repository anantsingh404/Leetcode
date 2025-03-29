class Solution {
public:
const int MOD = 1e9 + 7;
int pw(int base,int n)
{
    if(n==0)
    {
        return 1;
    }
    int x=pw(base,n/2);
    if(n%2)
    {
    return(int)((((1ll*x*x)%MOD)*base)%MOD);
    }
    return (int)((1ll*x*x)%MOD);

}
    
vector<int> prime; // Stores prime numbers

// Function to count distinct prime factors of x
int countPrimeFactors(int x, vector<int>& spf) {
    unordered_set<int> factors;
    while (x > 1) {
        factors.insert(spf[x]);
        x /= spf[x];
    }
    return factors.size();
}

// Function to compute maximum score
int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> spf(1e5 + 1, 0); // Smallest prime factor array

    // **Sieve of Eratosthenes with Smallest Prime Factor (SPF)**
    for (int i = 2; i <= 1e5; i++) {
        if (spf[i] == 0) { // i is a prime
            prime.push_back(i);
            for (int j = i; j <= 1e5; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }

    // Compute distinct prime factor count for each element in nums
    vector<int> primeScores(n, 0);
    for (int i = 0; i < n; i++) {
        primeScores[i] = countPrimeFactors(nums[i], spf);
    }

    // **Find left and right contributions using a monotonic stack**
    vector<int> left(n, 0), right(n, 0);
    stack<int> st;

    // Left Contribution
    for (int i = 0; i < n; i++) {
        while (!st.empty() && primeScores[i] > primeScores[st.top()]) {
            st.pop();
        }
        left[i] = (st.empty() ? i + 1 : i - st.top());
        st.push(i);
    }

    while (!st.empty()) st.pop(); // Clear stack

    // Right Contribution
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && primeScores[i] >= primeScores[st.top()]) {
            st.pop();
        }
        right[i] = (st.empty() ? n - i : st.top() - i);
        st.push(i);
    }

    // **Store elements and their contribution counts**
    vector<pair<int, long long>> elements;
    for (int i = 0; i < n; i++) {
        elements.push_back({nums[i], 1ll*left[i] * right[i]});
    }

    // Sort elements in descending order of value
    sort(elements.rbegin(), elements.rend());

    // **Calculate maximum possible score**
    long long score = 1;
    for (auto& [value, contribution] : elements) {
        int count = min(1ll*k, contribution);
        k=k-count;
        score=(score*pw(value,count))%MOD;
    }

    return score;
}
};