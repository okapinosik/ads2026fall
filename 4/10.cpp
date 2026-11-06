#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Если K превышает количество элементов N, выводим -1
    if (k > n) {
        cout << -1 << "\n";
        return 0;
    }

    // Сортируем массив по возрастанию. 
    // In-order обход BST вернет элементы именно в этом порядке.
    sort(a.begin(), a.end());

    // Выводим K-й элемент (0-индексация, поэтому k - 1)
    cout << a[k - 1] << "\n";

    return 0;
}