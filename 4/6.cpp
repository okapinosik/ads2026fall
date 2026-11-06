#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Функция вставки элемента в BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Подсчет узлов, имеющих одновременно левого и правого ребенка
int countTriangles(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    // Если у узла есть оба ребенка, он образует 1 треугольник
    int has_both = (root->left != nullptr && root->right != nullptr) ? 1 : 0;

    // Рекурсивно считаем количество треугольников в левом и правом поддеревьях
    return has_both + countTriangles(root->left) + countTriangles(root->right);
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int a_i;
        cin >> a_i;
        root = insert(root, a_i);
    }

    cout << countTriangles(root) << "\n";

    return 0;
}