#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long count_in_range(const vector<long long>& a, long long l, long long r) {
    if (l > r) return 0;
    auto it1 = lower_bound(a.begin(), a.end(), l);
    auto it2 = upper_bound(a.begin(), a.end(), r);
    return distance(it1, it2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (q--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }

        long long ans = 0;
        if (l2 <= r1) {
            ans = count_in_range(a, l1, max(r1, r2));
        } else {
            ans = count_in_range(a, l1, r1) + count_in_range(a, l2, r2);
        }

        cout << ans << "\n";
    }

    return 0;
}