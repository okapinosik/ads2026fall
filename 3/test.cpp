#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    if (!(cin >> n >> k)) return 0;
    
    vector<int> req(n);
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        req[i] = max(x2, y2);
    }
    
    sort(req.begin(), req.end());
    
    // Нам нужно K пастбищ, значит берем элемент с индексом K - 1
    cout << req[k - 1] << "\n";
    
    return 0;
}