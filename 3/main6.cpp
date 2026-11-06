#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(long long K, const vector<long long>& bags, long long H) {
    long long total_hours = 0;
    for (long long x : bags) {
        total_hours += (x + K - 1) / K;
        if (total_hours > H) {
            return false; 
        }
    }
    return total_hours <= H;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long h;
    cin >> n >> h;

    vector<long long> bags(n);
    long long max_bag = 0;
    for (int i = 0; i < n; ++i) {
        cin >> bags[i];
        max_bag = max(max_bag, bags[i]);
    }

    long long low = 1, high = max_bag;
    long long ans = max_bag;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, bags, h)) {
            ans = mid;   
            high = mid - 1;  
        } else {
            low = mid + 1;    
        }
    }

    cout << ans << "\n";

    return 0;
}