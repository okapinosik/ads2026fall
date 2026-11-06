#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if ((a[i] >= l1 && a[i] <= r1) || (a[i] >= l2 && a[i] <= r2)) {
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}