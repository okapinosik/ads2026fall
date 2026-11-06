#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

bool check(double len, const vector<double>& a, int k) {
    if (len <= 0) return true;
    long long count = 0;
    for (double rope : a) {
        count += static_cast<long long>(rope / len);
    }
    return count >= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<double> a(n);
    double max_len = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_len = max(max_len, a[i]);
    }

    double low = 0.0, high = max_len;
    
    for (int iter = 0; iter < 100; ++iter) {
        double mid = low + (high - low) / 2.0;
        if (check(mid, a, k)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << fixed << setprecision(9) << low << "\n";

    return 0;
}