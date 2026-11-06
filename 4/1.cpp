#include <iostream>
#include <vector>
#include <string>

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

    if (val <= root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}

int main() {
    int N, M;
    cin >> N >> M;

    Node* root = nullptr;

    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        root = insert(root, val); 
    }

    for (int i = 0; i < M; ++i) {
        string path;
        cin >> path;
        
        Node* curr = root; 
        
        for (char c : path) {
            if (curr == nullptr) break; 
            
            if (c == 'L') {
                curr = curr->left;
            } else if (c == 'R') {
                curr = curr->right;
            }
        }
        if (curr != nullptr) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}