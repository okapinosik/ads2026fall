#include <bits/stdc++.h>
using namespace std;

vector<int> left_child;
vector<int> right_child;
vector<int> depth;
int max_diameter = 0;

// Рекурсивный подсчет высоты поддерева и обновление максимального диаметра
int get_height_and_diameter(int u) {
    if (u == 0) return 0; // Базовый случай: пустое поддерево

    int h_left = get_height_and_diameter(left_child[u]);
    int h_right = get_height_and_diameter(right_child[u]);

    // Максимальное число вершин на пути, проходящем через узел u
    max_diameter = max(max_diameter, 1 + h_left + h_right);

    // Высота текущего поддерева
    return 1 + max(h_left, h_right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    left_child.resize(N + 1, 0);
    right_child.resize(N + 1, 0);
    depth.resize(N + 1, 0);

    set<pair<int, int>> bst; // Хранит пары {значение, id_узла}
    int node_count = 0;

    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;

        // Проверка на дубликаты (игнорируем, если значение уже существует)
        auto it = bst.lower_bound({val, 0});
        if (it != bst.end() && it->first == val) {
            continue; 
        }

        node_count++;
        int u = node_count;

        // Первый уникальный элемент — корень дерева
        if (u == 1) {
            bst.insert({val, u});
            depth[u] = 1;
            continue;
        }

        // Поиск преемника (succ) и предшественника (pred) в set
        auto upper_it = bst.upper_bound({val, N + 1});
        int succ_id = (upper_it != bst.end()) ? upper_it->second : 0;
        int pred_id = 0;

        if (upper_it != bst.begin()) {
            auto pred_it = prev(upper_it);
            pred_id = pred_it->second;
        }

        int depth_succ = succ_id ? depth[succ_id] : 0;
        int depth_pred = pred_id ? depth[pred_id] : 0;

        // Родителем становится узел с большей глубиной
        if (depth_succ > depth_pred) {
            left_child[succ_id] = u;
            depth[u] = depth[succ_id] + 1;
        } else {
            right_child[pred_id] = u;
            depth[u] = depth[pred_id] + 1;
        }

        bst.insert({val, u});
    }

    if (node_count == 0) {
        cout << 0 << "\n";
        return 0;
    }

    // Обход дерева для нахождения диаметра
    get_height_and_diameter(1);

    cout << max_diameter << "\n";

    return 0;
}