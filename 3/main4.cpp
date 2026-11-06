#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    int p;
    cin >> p;
    while (p--) {
        long long mark_power;
        cin >> mark_power;
        auto it = upper_bound(a.begin(), a.end(), mark_power);
        int count = distance(a.begin(), it);
        long long sum = pref[count];

        cout << count << " " << sum << "\n";
    }

    return 0;
}