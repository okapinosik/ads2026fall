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

Node* findNode(Node* root, int k) {
    if (root == nullptr || root->val == k) {
        return root;
    }
    if (k < root->val) {
        return findNode(root->left, k);
    } else {
        return findNode(root->right, k);
    }
}


void preOrder(Node* root) {
    if (root == nullptr) return;
    
    cout << root->val << " "; 
    preOrder(root->left);     
    preOrder(root->right);    
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

    int k;
    cin >> k;

    Node* target = findNode(root, k);
    preOrder(target);
    cout << "\n";

    return 0;
}