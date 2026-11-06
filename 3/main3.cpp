#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> pref(n);
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        if (i == 0) {
            pref[i] = a;
        } else {
            pref[i] = pref[i - 1] + a;
        }
    }

    for (int i = 0; i < m; ++i) {
        long long b;
        cin >> b;
        auto it = lower_bound(pref.begin(), pref.end(), b);
        int block_num = distance(pref.begin(), it) + 1;
        cout << block_num << "\n";
    }

    return 0;
}