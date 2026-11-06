#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

bool check(long long max_sum, const vector<long long>& a, int k) {
    int blocks_count = 1;
    long long current_sum = 0;

    for (long long x : a) {
        if (x > max_sum) {
            return false; 
        }
        if (current_sum + x > max_sum) {
            blocks_count++;
            current_sum = x;
        } else {
            current_sum += x;
        }
    }

    return blocks_count <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    long long low = 0;
    long long high = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        low = max(low, a[i]);
        high += a[i];
    }

    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, a, k)) {
            ans = mid;
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }

    cout << ans << "\n";

    return 0;
}