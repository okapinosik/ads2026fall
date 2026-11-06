#include <iostream>
using namespace std;


struct Node {
    int val;
    Node* left;
    Node* right;
    
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

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

Node* findNode(Node* root, int x) {
    if (root == nullptr || root->val == x) {
        return root;
    }
    
    if (x < root->val) {
        return findNode(root->left, x);
    } else {
        return findNode(root->right, x);
    }
}

int getSubtreeSize(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + getSubtreeSize(root->left) + getSubtreeSize(root->right);
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

    int x;
    cin >> x;

    Node* targetNode = findNode(root, x);
    cout << getSubtreeSize(targetNode) << "\n";

    return 0;
}