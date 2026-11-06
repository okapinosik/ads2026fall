#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    vector<int> queries(t);
    for (int i = 0; i < t; ++i) {
        cin >> queries[i];
    }

    int n, m;
    cin >> n >> m;

    unordered_map<int, pair<int, int>> pos;
    pos.reserve(n * m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int val;
            cin >> val;
            pos[val] = {i, j};
        }
    }

    for (int i = 0; i < t; ++i) {
        auto it = pos.find(queries[i]);
        if (it != pos.end()) {
            cout << it->second.first << " " << it->second.second << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}