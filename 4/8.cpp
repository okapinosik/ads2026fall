#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Вставка элемента в BST
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

// Обратный центрированный обход (Right -> Node -> Left)
// Преобразует дерево и выводит новые значения в порядке возрастания
void convertAndPrint(Node* root, int& sum) {
    if (root == nullptr) return;

    // 1. Идем в правое поддерево (там находятся большие элементы)
    convertAndPrint(root->right, sum);

    // 2. Обрабатываем текущий узел
    sum += root->val;
    root->val = sum;
    cout << root->val << " ";

    // 3. Идем в левое поддерево (там находятся меньшие элементы)
    convertAndPrint(root->left, sum);
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

    int sum = 0;
    convertAndPrint(root, sum);
    cout << "\n";

    return 0;
}