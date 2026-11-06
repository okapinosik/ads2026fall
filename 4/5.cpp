#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // Массивы для хранения левого и правого ребенка для каждой вершины
    vector<int> left_child(n + 1, 0);
    vector<int> right_child(n + 1, 0);

    // Считываем n - 1 ребер
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) {
            left_child[x] = y; // Левый сын
        } else {
            right_child[x] = y; // Правый сын
        }
    }


    queue<int> q;
    q.push(1); 

    int max_width = 0;

    while (!q.empty()) {
        int level_size = q.size(); 
        max_width = max(max_width, level_size);

        for (int i = 0; i < level_size; ++i) {
            int curr = q.front();
            q.pop();

            if (left_child[curr] != 0) {
                q.push(left_child[curr]);
            }
            if (right_child[curr] != 0) {
                q.push(right_child[curr]);
            }
        }
    }

    cout << max_width << "\n";

    return 0;
}