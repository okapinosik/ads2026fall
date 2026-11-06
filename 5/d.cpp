#include <iostream>
#include <vector>
using namespace std;

struct heap {
    vector<long long> a;
    void heapify(int i) {
        int l = 2 * i + 1, r = 2 * i + 2;
        int s = i;
        if(l < a.size() && a[l] < a[s]) s = l;
        if(r < a.size() && a[r] < a[s]) s = r;
        if(s != i) {swap(a[i], a[s]); heapify(s);}
    }
    void push(long long x) {
        a.push_back(x);
        int i = a.size() - 1;
        while(i > 0) {
            int p = (i - 1) / 2;
            if(a[p] <= a[i]) break;
            swap(a[p], a[i]);
            i = p;
        }
    }
    long long pop() {
        long long x = a[0];
        a[0] = a.back();
        a.pop_back();
        if(!a.empty()) heapify(0);
        return x;
    }
    int size() {return a.size();}
};
int main() {
    int n;
    long long k;
    cin >> n >> k;
    heap h;
    while(n--) {long long x; cin >> x; h.push(x);}
    int ans = 0;
    while(h.size() > 0 && h.a[0] < k) {
        if(h.size() < 2) {
            cout << -1; return 0;
        }
        long long a = h.pop();
        long long b = h.pop();
        h.push(a + 2 * b);
        ans++;
    }
    cout << ans;
}