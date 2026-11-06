#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long long> req_side(n);
    for (int i = 0; i < n; ++i) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        req_side[i] = max(x2, y2);
    }
    nth_element(req_side.begin(), req_side.begin() + k - 1, req_side.end());

    cout << req_side[k - 1] << "\n";

    return 0;
}