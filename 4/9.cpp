#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Классическая функция вставки элемента в BST
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

// Рекурсивный подсчет количества листьев
int countLeaves(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    // Если у узла нет ни левого, ни правого ребенка — это лист
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    // Иначе суммируем листья из левого и правого поддеревьев
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int p_i;
        cin >> p_i;
        root = insert(root, p_i);
    }

    cout << countLeaves(root) << "\n";

    return 0;
}